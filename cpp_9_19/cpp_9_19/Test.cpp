#include <iostream>
using namespace std;

class A
{
public:
	A()
		: _a(new int[10])
		, _b(10)
	{
		for (int i = 0; i < 10; i++)
		{
			_a[i] = i;
		}
	}
	
	int& fun()
	{
		return _a[5];
	}

	int operator[](int pos)
	{
		return _a[pos];
	}
private:
	int* _a;
	int _b;
};

int main()
{
	A a;
	cout << a[5] << endl;
	int& p = a.fun();
	p = 10;
	cout << a[5] << endl;
	return 0;
}