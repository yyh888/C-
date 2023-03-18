#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <cassert>

using std::cout;
using std::endl;

namespace yyh
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		string(const char* str = "")
			: _size(strlen(str))
			, _capacity(_size)
		{
			_str = new char[_capacity + 1];// _capacity表示有效字符个数
			strcpy(_str, str);
			cout << "string(const char* str) -- 构造函数" << endl;
		}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		// 拷贝构造
		string(const string& s)
			: _size(strlen(s._str))
			, _capacity(s._size)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, s._str);
			cout << "string(const string& s) -- 深拷贝" << endl;
		}

		// 移动构造
		string(string&& s)
		{
			cout << "string(string&& s) -- 移动拷贝" << endl;
			swap(s);
		}

		// 赋值重载
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- 深拷贝" << endl;
			string tmp(s);
			swap(tmp);
			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;

				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str = nullptr;
		size_t _size = 0;
		size_t _capacity = 0;
	};
}


struct A
{
	A(int a = 1, const char* str = " ")
		: _a(a)
		, _str(str)
	{}
	int _a;
	yyh::string _str;
};

int main()
{
	std::list<A> lt;
	A tmp{ 10, "tttt" };
	lt.emplace_back(tmp);// 左值
	cout << '\n';
	lt.emplace_back(1, "aaa");// 右值

	return 0;
}




//int main()
//{
//	std::list<int> lt;
//	lt.emplace_back();
//	lt.emplace_back(1);
//	lt.emplace_back(2);
//	for (auto& e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << '\n';
//	return 0;
//}




//template <class T>
//void printArg(T val)
//{
//	cout << val << " ";
//}
//
//template <class ...Args>
//void fun(Args... args)
//{
//	int arr[] = { (printArg(args), 0)... };
//	cout << endl;
//}
//
//int main()
//{
//	fun(1, 1.1, std::string("abc"));
//	return 0;
//}





//void fun()
//{
//	cout << endl;
//}
//
//template <class T, class ...Args>
//void fun(T val, Args... args)
//{
//	cout << val << " ";
//	fun(args...);
//}
//
//int main()
//{
//	fun(1, 1.1, std::string("abc"));
//	return 0;
//}