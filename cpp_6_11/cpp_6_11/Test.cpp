#include<iostream>
using namespace std;


//struct Person
//{
//	char name[20];
//	int age;
//};
//
//
//int main()
//{
//	char str[10];
//	cin >> str;
//	cout << str << endl;
//	struct Person p = { "Ð¡Àî", 20 };
//	printf("%s, %d", p.name, p.age);
//	return 0;
//}


//void Func(int a = 1, int b = 2, int c = 3)
//{
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//}
//
//
//int main()
//{
//	Func(10);
//	return 0;
//}


//int Add(int a, int b)
//{
//	return a + b;
//}
//
//double Add(double a, double b)
//{
//	return a + b;
//}
//
//
//int main()
//{
//	cout << Add(1, 2) << endl;
//	cout << Add(1.1, 2.2) << endl;
//	return 0;
//}



//int main()
//{
//	int a = 10;
//	int& b = a;
//	b = 20;
//	cout << a << endl;
//	return 0;
//}


void Swap(int& r1, int& r2)
{
	int tmp = r1;
	r1 = r2;
	r2 = tmp;
}


int main()
{
	int a = 1, b = 2;
	Swap(a, b);
	cout << a << b << endl;
	return 0;
}