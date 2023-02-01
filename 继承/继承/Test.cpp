#include <iostream>

using namespace std;

class A
{
public:
	A(int a = 1)
		: _a(a)
	{}

	int _a;
};

class B : public A
{
public:
	B(int a = 2)
		: _a(a)
	{}

	int _a;
};

int main()
{
	A one;
	B two;
	one._a = 10;
	two._a = 20;
	cout << two.A::_a << endl;
	return 0;
}