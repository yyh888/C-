#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <assert.h>
#include <cstring>

using std::cout;
using std::endl;
using std::swap;

//int main()
//{
//	// ��ֵ
//	int a = 0;
//	int* b = nullptr;
//	const int c = 1;
//	const int* d = nullptr;
//	// ��ֵ����
//	int& ra = a;
//	int*& rb = b;
//	const int& rc = c;
//	const int*& rd = d;
//	// ��ֵ���ò���������ֵ����const��ֵ���ÿ���
//	//int& e = 10;
//	//int& f = (a + c);
//	const int& e = 10;
//	const int& f = (a + c);
//	return 0;
//}

//int main()
//{
//	// ֻ��������ֵ
//	int&& a = 10;
//	a++;
//	int ret = 0;
//	//int&& b = ret;// ����������ֵ
//	// ��������move�����ֵ
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
//		// ��������
//		string(const string& s)
//		{
//			cout << "string(const string& s) -- ���" << endl;
//			string tmp(s._str);
//			swap(tmp);
//		}
//
//		// �ƶ�����
//		string(string&& s)
//		{
//			cout << "string(string&& s) -- �ƶ�����" << endl;
//			swap(s);
//		}
//
//		// ��ֵ����
//		string& operator=(const string& s)
//		{
//			cout << "string& operator=(string& s) -- ���" << endl;
//			string tmp(s);
//			swap(tmp);
//			return *this;
//		}
//
//		// �ƶ���ֵ
//		string& operator=(string&& s)
//		{
//			cout << "string& operator=(string&& s) -- �ƶ���ֵ" << endl;
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
//	//fun1(a);// ��ֵ����������ֵ
//	return 0;
//}

void Fun(int& x) { cout << "��ֵ����" << endl; }
void Fun(const int& x) { cout << "const ��ֵ����" << endl; }

void Fun(int&& x) { cout << "��ֵ����" << endl; }
void Fun(const int&& x) { cout << "const ��ֵ����" << endl; }


// ��������
template <class T>
void fun(T&& i)
{
	// ����ת��������ԭ������
	Fun(std::forward<T>(i));
}

int main()
{
	int a = 1;
	fun(a);// ��ֵ
	fun(std::move(a));// ��ֵ
	const int b = 1;
	fun(b);// const��ֵ
	fun(std::move(b));// const��ֵ
	return 0;
}