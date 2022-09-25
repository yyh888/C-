#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

namespace yyh
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator& begin()
		{
			return _start;
		}

		iterator& end()
		{
			return _finish;
		}

		const_iterator& begin() const
		{
			return _start;
		}

		const_iterator& end() const
		{
			return _finish;
		}

		vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _endofstorage - _start;
		}
		
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				//扩容
				T* tmp = new T[n];
				if (_start)//不为空
				{
					//拷贝
					memcpy(tmp, _start, sizeof(T) * size());
					delete[]_start;
				}
				_finish = tmp + size();
				_start = tmp;
				_endofstorage = _start + n;
			}
		}

		void resize(size_t n， const T& val = T())// 匿名对象
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					// 扩容
					reserve(n);
					while (_finish != _start + n)
					{
						*_finish = val;
						finish++;
					}
				}
			}
		}

		void push_back(const T& x)
		{
			if (_finish == _endofstorage)
			{
				
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			*_finish = x;
			++_finish;
		}

		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};

	void test1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		for (size_t i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;
		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}

int main()
{
	yyh::test1();
	return 0;
}