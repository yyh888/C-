#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
#include <string.h>
using namespace std;

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
//			swap(s);
//			cout << "string(string&& s) -- �ƶ�����" << endl;
//		}
//
//		// ��ֵ����
//		string& operator=(const string& s)
//		{
//			cout << "string& operator=(string s) -- ���" << endl;
//			string tmp(s);
//			swap(tmp);
//			return *this;
//		}
//
//		// �ƶ���ֵ
//		string& operator=(string&& s)
//		{
//			swap(s);
//			cout << "string& operator=(string&& s) -- �ƶ���ֵ" << endl;
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
//}
//
//class A
//{
//public:
//	A(int a = 1, const char* s = "")
//		: _a(a)
//		, _s(s)
//	{}
//	// ֻ���ƶ�����û�п��������ƥ������
//	A& operator=(const A& aa) = default;
//	A& operator=(A&& aa) = default;
//
//	A(A&& a) = default;
//
//	~A() {}
//private:
//	int _a = 1;
//	yyh::string _s;
//};
//
//int main()
//{
//	A a;
//	A b;
//	A c;
//	// ��default
//	A d(move(b));
//	c = move(a);
//	return 0;
//}

//class A
//{
//public:
//	A(){}
//
//	A(const A& aa) = delete;
//
//	~A()
//	{
//		delete[]_p;
//	}
//
//private:
//	int* _p = new int[10];
//};
//
//int main()
//{
//	A a;
//	A b(a);
//	return 0;
//}


int main()
{
	auto compare = [](int x, int y) {return x > y; };
	cout << compare(1, 2) << endl;
	cout << compare(3, 2) << endl;
	return 0;
}