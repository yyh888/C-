#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


//namespace yyh
//{
//	class string
//	{
//	public:
//		string(const char* str)
//		{
//			_str = new char[strlen(str) + 1];
//			strcpy(_str, str);
//		}
//		char& operator[](size_t i)
//		{
//			return _str[i];
//		}
//	private:
//		char* _str;
//	};
//}
//
//
//
//int main()
//{
//	yyh::string s1("aaaaaaaaaaa");
//	s1[2] += 1;
//	cout << s1[2] << endl;
//	return 0;
//}



//class A
//{
//public:
//	A(int a = 1)
//	{
//		_a = 1;
//	}
//private:
//	int _a;
//};
//
//
//class B
//{
//public:
//private:
//	A a;
//	int _b;
//};
//
//int main()
//{
//	B b;
//	return 0;
//}


namespace yyh
{
	class string
	{
	public:
		string(const char* str)
		{
			_a = new char[strlen(str) + 1];
			strcpy(_a, str);
		}
		~string()
		{
			delete[]_a;
			_a = nullptr;
		}
	private:
		char* _a;
	};
}


int main()
{
	yyh::string s1("aaaaaaa");
	return 0;
}