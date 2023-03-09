#include <iostream>

using namespace std;

//class A
//{
//public:
//	A(int a)
//		: _a(a)
//	{
//		cout << "A()" << endl;
//	}
//protected:
//	int _a;
//};
//
//class B : public A
//{
//public:
//
//protected:
//	int _b;
//};
//
//int main()
//{
//	B b;
//	return 0;
//}


class A
{
public:
	A(int a = 1)
		: _a(a)
	{
		cout << "A()" << endl;
	}

	A(const A& aa)
		: _a(aa._a)
	{
		cout << "A(const A& aa)" << endl;
	}
protected:
	int _a;
};

class B : public A
{
public:
	B(int a = 1, int b = 2)
		: A(a)
		, _b(b)
	{}

	B(const B& bb)
		//: A(bb)// ÇÐÆ¬
		: _b(bb._b)
	{
		cout << "B(const B& bb)" << endl;
	}
protected:
	int _b;
};

int main()
{
	B b1(3, 4);
	B b2(b1);
	return 0;
}


//class A
//{
//public:
//	A(int a = 1)
//		: _a(a)
//	{
//		cout << "A()" << endl;
//	}
//
//	A(const A& aa)
//		: _a(aa._a)
//	{}
//
//	A& operator=(const A& aa)
//	{
//		if (this != &aa)
//		{
//			_a = aa._a;
//		}
//		cout << "A& operator=(const A& aa)" << endl;
//		return *this;
//	}
//protected:
//	int _a;
//};
//
//class B : public A
//{
//public:
//	B(int a = 1, int b = 2)
//		: A(a)
//		, _b(b)
//	{}
//
//	B(const B& bb)
//		: A(bb)// ÇÐÆ¬
//		, _b(bb._b)
//	{}
//
//	B& operator=(const B& bb)
//	{
//		if (this != &bb)
//		{
//			//A::operator=(bb);// ÇÐÆ¬
//			_b = bb._b;
//		}
//		cout << "B& operator=(const B& bb)" << endl;
//		return *this;
//	}
//protected:
//	int _b;
//};
//
//int main()
//{
//	B b1(3, 4);
//	B b2(5, 6);
//	b1 = b2;
//	return 0;
//}