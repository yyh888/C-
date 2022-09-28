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
		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}

		/*vector(const vector<T>& v)
		{
			_start = new T[v.capacity()];
			_finish = _start + v.size();
			_endofstorage = _start + v.capacity();
			memcpy(_start, v._start, v.size() * sizeof(T));
		}*/

		// 构造
		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}

		//现代写法
		vector(const vector<T>& v)
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			vector<T> tmp(v.begin(), v.end());
			swap(tmp);
		}

		// v2 = v1
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}

		~vector()
		{
			if (_start)
			{
				delete[]_start;
				_finish = _endofstorage = nullptr;
			}
		}

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
			size_t sz = size();
			if (n > capacity())
			{
				//扩容
				T* tmp = new T[n];
				if (_start)//不为空
				{
					//拷贝
					//memcpy(tmp, _start, sizeof(T) * size());
					for (size_t i = 0; i < sz; i++)
					{
						tmp[i] = _start[i];
					}
					delete[]_start;
				}
				_start = tmp;
				_finish = _start + sz;
				_endofstorage = _start + n;
			}
		}

		void resize(size_t n, const T& val = T())// 匿名对象
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
						_finish++;
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

		void pop_back()
		{
			assert(size() > 0);
			--_finish;
		}

		//防止迭代器失效
		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start && pos <= _finish);
			if (_finish == _endofstorage)
			{
				// 扩容会导致pos失效，扩容需要更新一下pos
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + len;
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				end--;
			}
			*pos = x;
			++_finish;
			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);
			iterator end = pos;
			while (end < _finish - 1)
			{
				*end = *(end + 1);
				end++;
			}
			_finish--;
			return pos;
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

	void test2()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(6);
		vector<int> v2(v1);
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test3()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		//v.insert(v.begin(), 0);
		for (auto& e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test4()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(6);
		// 删除所有偶数
		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				it = v.erase(it);// 缩容后失效
			}
			else
			{
				it++;
			}
		}
		for (auto& e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}

int main()
{
	//yyh::test1();
	//yyh::test2();
	yyh::test4();
	return 0;
}