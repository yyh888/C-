//#include<stdio.h>
//#include<string.h>
//
//
//// yyh为命名空间的名称
//namespace yyh
//{
//	int strlen = 0;
//	int Add(int x, int y)
//	{
//		return x + y;
//	}
//}
//
//namespace yyh
//{
//	int a = 0;
//}
//
//
//using namespace yyh;
//int main()
//{
//	printf("%d", Add(1, 2));
//	return 0;
//}


#include<iostream>
using std::cout;
using std::cin;
using std::endl;


//void Fun(int a, int b = 1, int c = 1)
//{
//	cout << "a = " << a << " ";
//	cout << "b = " << b << " ";
//	cout << "c = " << c << endl;
//}


//void fun(int a = 1, int b = 1) {}
//void fun(int a = 2, double b = 3) {}
//
//
//
//int main()
//{
//	fun(1, 2);
//	return 0;
//}



//int main()
//{
//	char a[10];
//	cin >> a;
//	cout << a << endl;
//	return 0;
//}


//void Fun(int a = 0, int b = 1) {}
//void Fun(int a = 0, int b = 1, int c = 2) {}
//
//
//int main()
//{
//	Fun(1, 2);
//	return 0;
//}



//int main()
//{
//	int a = 0;
//	int& b = a;
//	return 0;
//}




#include"Test.h"


//Test.h
/*int Add(int a, int b);
double Add(double a, double b)*/;

////Test.cpp
//int Add(int a, int b)
//{
//	return a + b;
//}
//
//double Add(double a, double b)
//{
//	return a + b;
//}

//main.cpp
//int main()
//{
//	Add(1, 2);//call Add(地址)
//	Add(1.1, 1.2);//call Add(地址)
//	return 0;
//}




//int main()
//{
//	int a = 10;
//	int& b = a;//b为a的引用
//	return 0;
//}



//int main()
//{
//	int& a;//error1
//
//	int b = 0;
//	int& c = b;
//	int d = 1;
//	c = d;//这里不是让c变成d的别名，而是把d的
//	      //值赋值给c(也就是b)
//	return 0;
//}



int main()
{

	return 0;
}