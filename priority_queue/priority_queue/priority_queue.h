#pragma once
#include <iostream>
#include<vector>
#include<functional>
using namespace std;

namespace yyh
{
    template<class T>
    class less
    {
    public:
        bool operator()(const T& x1, const T& x2)
        {
            return x1 < x2;
        }
    };

    template<class T>
    class greater
    {
    public:
        bool operator()(const T& x1, const T& x2)
        {
            return x1 > x2;
        }
    };

    template <class T, class Container = vector<T>, class Compare = less<T> >
    class priority_queue
    {
    public:
        priority_queue()
        {}

        template <class InputIterator>
        priority_queue(InputIterator first, InputIterator last)
            : c(first, last)
        {
            for (int i = (size() - 1 - 1) / 2; i >= 0; i--)
            {
                adjustdown(i);
            }
        }

        bool empty() const
        {
            return c.empty();
        }

        size_t size() const
        {
            return c.size();
        }

        void adjustdown(int parent)
        {
            int child = 2 * parent + 1;
            while (child < size())
            {
                if (child + 1 < size() && comp(c[child], c[child + 1]))
                {
                    child++;
                }
                if (comp(c[parent], c[child]))
                {
                    swap(c[child], c[parent]);
                    parent = child;
                    child = 2 * parent + 1;
                }
                else break;
            }
        }

        void adjustup(int child)
        {
            int parent = (child - 1) / 2;
            while (child > 0)
            {
                if (comp(c[parent], c[child]))
                {
                    swap(c[child], c[parent]);
                    child = parent;
                    parent = (child - 1) / 2;
                }
                else break;
            }
        }

        T& top() const
        {
            return c[0];
        }

        void push(const T& x)
        {
            c.push_back(x);
            adjustup(c.size() - 1);
        }

        void pop()
        {
            swap(c[0], c[size() - 1]);
            c.pop_back();
            adjustdown(0);
        }

    private:
        Container c;
        Compare comp;
    };
};