#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <assert.h>
#include <cstring>

using std::cout;
using std::endl;
using std::swap;

//int main()
//{
//	// 左值
//	int a = 0;
//	int* b = nullptr;
//	const int c = 1;
//	const int* d = nullptr;
//	// 左值引用
//	int& ra = a;
//	int*& rb = b;
//	const int& rc = c;
//	const int*& rd = d;
//	// 左值引用不能引用右值，但const左值引用可以
//	//int& e = 10;
//	//int& f = (a + c);
//	const int& e = 10;
//	const int& f = (a + c);
//	return 0;
//}

//int main()
//{
//	// 只能引用右值
//	int&& a = 10;
//	a++;
//	int ret = 0;
//	//int&& b = ret;// 不能引用左值
//	// 可以引用move后的左值
//	int&& b = std::move(ret);
//	return 0;
//}

//template <class T>
//T& fun()
//{
//	T a;
//	return a;
//}

//namespace yyh
//{
//	class string
//	{
//	public:
//		typedef char* iterator;
//		iterator begin()
//		{
//			return _str;
//		}
//
//		iterator end()
//		{
//			return _str + _size;
//		}
//
//		string(const char* str = "")
//			:_size(strlen(str))
//			, _capacity(_size)
//		{
//			_str = new char[_capacity + 1];
//			strcpy(_str, str);
//		}
//
//		void swap(string& s)
//		{
//			::swap(_str, s._str);
//			::swap(_size, s._size);
//			::swap(_capacity, s._capacity);
//		}
//
//		// 拷贝构造
//		string(const string& s)
//		{
//			cout << "string(const string& s) -- 深拷贝" << endl;
//			string tmp(s._str);
//			swap(tmp);
//		}
//
//		// 移动构造
//		string(string&& s)
//		{
//			cout << "string(string&& s) -- 移动拷贝" << endl;
//			swap(s);
//		}
//
//		// 赋值重载
//		string& operator=(const string& s)
//		{
//			cout << "string& operator=(string& s) -- 深拷贝" << endl;
//			string tmp(s);
//			swap(tmp);
//			return *this;
//		}
//
//		// 移动赋值
//		string& operator=(string&& s)
//		{
//			cout << "string& operator=(string&& s) -- 移动赋值" << endl;
//			swap(s);
//			return *this;
//		}
//
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//
//		char& operator[](size_t pos)
//		{
//			assert(pos < _size);
//			return _str[pos];
//		}
//
//		void reserve(size_t n)
//		{
//			if (n > _capacity)
//			{
//				char* tmp = new char[n + 1];
//				strcpy(tmp, _str);
//				delete[] _str;
//				_str = tmp;
//
//				_capacity = n;
//			}
//		}
//
//		void push_back(char ch)
//		{
//			if (_size >= _capacity)
//			{
//				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
//				reserve(newcapacity);
//			}
//
//			_str[_size] = ch;
//			++_size;
//			_str[_size] = '\0';
//		}
//
//		string& operator+=(char ch)
//		{
//			push_back(ch);
//			return *this;
//		}
//
//		const char* c_str() const
//		{
//			return _str;
//		}
//	private:
//		char* _str = nullptr;
//		size_t _size = 0;
//		size_t _capacity = 0;
//	};
//
//	string Get()
//	{
//		string s = "123456";
//		return s;
//	}
//}
//
//int main()
//{
//	const yyh::string s("aaaaa");
//	yyh::string ret = s;
//	return 0;
//}


//void fun(int a)
//{
//	cout << "fun1(int a)" << endl;
//}
//
//void fun(int& a)
//{
//	cout << "fun2(int& a)" << endl;
//}
//
//int main()
//{
//	fun(1);
//	return 0;
//}

//void fun2(int&& i)
//{
//	cout << "fun2(int&& i)" << endl;
//}
//
//void fun2(int& i)
//{
//	cout << "fun2(int& i)" << endl;
//}
//
//void fun1(int&& i)
//{
//	cout << "fun1(int&& i)" << endl;
//	fun2(std::move(i));
//}
//
//int main()
//{
//	fun1(1);
//	return 0;
//}

//void fun1(int&& i)
//{
//	cout << "fun1(int&& i)" << endl;
//}
//
//int main()
//{
//	int a = 1;
//	//fun1(a);// 右值不能引用左值
//	return 0;
//}

void Fun(int& x) { cout << "左值引用" << endl; }
void Fun(const int& x) { cout << "const 左值引用" << endl; }

void Fun(int&& x) { cout << "右值引用" << endl; }
void Fun(const int&& x) { cout << "const 右值引用" << endl; }


// 万能引用
template <class T>
void fun(T&& i)
{
	// 完美转发，保持原本属性
	Fun(std::forward<T>(i));
}

int main()
{
	int a = 1;
	fun(a);// 左值
	fun(std::move(a));// 右值
	const int b = 1;
	fun(b);// const左值
	fun(std::move(b));// const右值
	return 0;
}