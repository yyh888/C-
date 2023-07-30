#include <iostream>
using namespace std;

class A
{
public:
	int _a;
};

class B : virtual public A
{
public:
	int _b;
};

class C : virtual public A
{
public:
	int _c;
};

class D : public B, public C
{
public:
	int _d;
};

int main()
{
	D d;
	d.B::_a = 3;
	cout << d.A::_a << endl;
	d.C::_a = 2;
	cout << d.A::_a << endl;
	return 0;
}

