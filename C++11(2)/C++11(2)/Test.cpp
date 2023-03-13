#include <iostream>

using namespace std;

//class A
//{
//public:
//	/*A()
//	{
//		cout << "A()" << endl;
//	}*/
//
//	A(const A& a)
//	{
//		cout << "A()" << endl;
//	}
//public:
//
//};
//
//int main()
//{
//	A a;
//	A b(a);
//	return 0;
//}


class A
{
public:
	A()
		: b(11)
	{
		p = new int[20];
		cout << "A()" << endl;
	}

	void fun()
	{
		A tmp(*this);
	}

private:
	A(const A& aa)
		: b(1)
	{
		cout << "A(const A& aa)" << endl;
	}


	int* p;
	int b;
};


int main()
{
	A a;
	a.fun();
	return 0;
}