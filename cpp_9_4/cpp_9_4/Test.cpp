#include <iostream>
using namespace std;

//class A
//{
//public:
//	A(int n = 5)
//	{
//		_a = new int[5];
//		cout << "A(int n = 5)" << endl;
//	}
//private:
//	int* _a;
//};
//
//
//int main()
//{
//	A* a = (A*)malloc(sizeof(A));
//	//new(a)A;
//	new(a)A(3);
//	return 0;
//}



//void Swap(int& x, int& y)
//{
//	int temp = x;
//	x = y;
//	y = temp;
//}
//
//void Swap(double& x, double& y)
//{
//	double temp = x;
//	x = y;
//	y = temp;
//}
//
//int main()
//{
//	int a = 1, b = 2;
//	double c = 1.1, d = 2.2;
//	cout << "a: " << a << " " << "b: " << b << endl;
//	cout << "c: " << c << " " << "d: " << d << endl;
//	Swap(a, b);
//	Swap(c, d);
//	cout << "a: " << a << " " << "b: " << b << endl;
//	cout << "c: " << c << " " << "d: " << d << endl;
//	return 0;
//}

////函数模板
//template <class T>//template <typename T>
//void Swap(T& x, T& y)
//{
//	T temp = x;
//	x = y;
//	y = temp;
//}



//template <class T1, class T2>
//T1 Add(const T1& a, const T2& b)
//{
//	T1 sum = a + b;
//	return sum;
//}
//
//int main()
//{
//	int a = 1;
//	double b = 1.1;
//	//cout << Add(a, b) << endl;
//	cout << Add((double)a, b) << endl;
//	cout << Add<double>(a, b) << endl;//显示实例化
//	cout << Add<int>(a, b) << endl;//显示实例化
//	return 0;
//}



//template <class T1, class T2>
//T1 Add(const T1& a, const T2& b)
//{
//	T1 sum = a + b;
//	return sum;
//}
//
//int Add(int& a, int& b)
//{
//	return a + b;
//}
//
//double Add(double& a, double& b)
//{
//	return a + b;
//}
//
//int main()
//{
//	int a = 1, b = 2;
//	double c = 1.1, d = 2.2;
//	cout << Add(a, b) << endl;// 1
//	cout << Add(c, d) << endl;// 2
//	cout << Add(a, c) << endl;// 3
//	return 0;;
//}

//typedef int STDataType;
////typedef char STDataType;
//
//class Stack
//{
//public:
//
//private:
//	STDataType* _a;
//	int _top;
//	int _size;
//};


template <class T>
class Stack
{
public:
	void Push(T& x);
private:
	T* _a;
	int _top;
	int _size;
};

template <class T>
void Stack<T>::Push(T& x)
{}