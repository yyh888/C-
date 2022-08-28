#include <iostream>
using namespace std;

class A
{
public:
	A()
	{
		cout << "A()" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
	A(const A& a)
	{
		cout << "A(const A& a)" << endl;
	}
	A& operator=(const A a)
	{
		cout << "A& operator=(const A a)" << endl;
		return *this;
	}
	void Print()
	{
		cout << "Print" << endl;
	}
};

void f1(const A a)
{

}

A f2()
{
	static A aa;
	return aa;
}

//A a;

int main()
{
	//A a1;
	//f1(a1);
	//f1(A());
	//f2();
	f2();
	f2();
	return 0;
}