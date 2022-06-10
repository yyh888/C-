#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"List.h"
//using namespace std;
////int main()
////{
////	std::cout << "hello world" << std::endl;
////	return 0;
////}
//
//using std::cout;
//using std::endl;
//
//
//
//namespace yyh
//{
//	int scanf = 20;
//	int strlen = 30;
//	int Add(int a, int b)
//	{
//		return a + b;
//	}
//	namespace N1
//	{
//		int a = 0;
//		int b = 0;
//		int Sub(int left, int right)
//		{
//			return left - right;
//		}
//	}
//}
//
//
//int a = 0;
//
//int main()
//{
//	/*printf("%x\n", scanf);
//	printf("%x\n", strlen);
//	printf("%x\n", yyh::scanf);
//	printf("%x\n", yyh::strlen);*/
//	printf("%d\n", yyh::Add(1, 2));
//	printf("%d\n", yyh::N1::Sub(2, 1));
//	yyh::ListNode* p = NULL;
//	int a = 1;
//	printf("%d\n", a);
//	printf("%d\n", ::a);
//	return 0;
//}


int main()
{
	std::cout << "hello world";
	std::cout << "hello world" << std::endl << std:: endl;

	int a = 0;
	int* p = &a;
	printf("%d,%p\n", a, p);
	std::cout << a << "," << p << std::endl;
	std::cin >> a;
	printf("%d,%p\n", a, p);
	char str[10];
	std::cin >> a;
	std::cin >> str;
	std::cout << str << std::endl;
	return 0;
}