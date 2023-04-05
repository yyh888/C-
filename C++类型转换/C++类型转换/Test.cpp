#include <iostream>

using std::cout;
using std::endl;

//int main()
//{
//	// 隐式类型转换
//	int Ival = 1;
//	double Dval = Ival;
//
//	// 显示类型转换
//	int* p = &Ival;
//	int pi = p;// error
//	int pi = (int)p;
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	double d = static_cast<int>(i);
//	int* p = nullptr;
//	int pi = static_cast<int>(p);// error
//
//	int pi = reinterpret_cast<int>(p);// correct
//	return 0;
//}

//int main()
//{
//	const int i = 1;
//	int* p = const_cast<int*>(&i);
//	*p = 3;
//	cout << b << endl;
//	return 0;
//}

//class A
//{
//public:
//	virtual void fun()
//	{
//		cout << &_a << endl;
//	}
//public:
//	int _a;
//};
//
//class B : public A
//{
//public:
//	void fun()
//	{
//		cout << &_b << endl;
//	}
//public:
//	int _b;
//};
//
//int main()
//{
//	A* pa = new A;
//	B* pb = (B*)pa;
//	pb->_b++;
//	return 0;
//}


class A
{
public:
	virtual void f() {}
public:
	int _a = 0;
};

class B : public A
{
public:
	int _b = 0;
};

void fun(A* pa)
{
	B* pb = dynamic_cast<B*>(pa);
	cout << pb << endl;
	if (pb)
	{
		pb->_a++;
		pb->_b++;
	}
}

int main()
{
	A a;
	B b;
	fun(&a);
	fun(&b);
	return 0;
}