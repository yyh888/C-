#include <iostream>
#include <string>

using namespace std;

//class Person
//{
//public:
//	void print()
//	{
//		cout << "Person()" << endl;
//	}
//protected:
//	string _name;
//	int _age;
//};
//
//class Student : public Person
//{
//protected:
//	int _Pnum;
//};
//
//class Teacher : public Person
//{
//protected:
//	int _Tnum;
//};
//
//
//int main()
//{
//	Student st;
//	Teacher te;
//	st.print();
//	te.print();
//	return 0;
//}

//class A
//{
//public:
//	int _a = 1;
//};
//
//class B : public A
//{
//public:
//	int _b = 2;
//};



//int main()
//{
//	B b;
//	A& pa = b;
//	++pa._a;
//	cout << b._a << endl;
//	return 0;
//}


//class A
//{
//public:
//
//protected:
//	int _a = 1;
//};
//
//class B : public A
//{
//public:
//	void Print()
//	{
//		cout << A::_a << endl;
//	}
//protected:
//	int _a = 2;
//};

//int main()
//{
//	B b;
//	b.Print();
//	return 0;
//}

//class A
//{
//public:
//	void Print()
//	{
//		cout << "A" << endl;
//	}
//protected:
//	int _a = 1;
//};
//
//class B : public A
//{
//public:
//	void Print(int i)
//	{
//		cout << "b" << endl;
//	}
//protected:
//	int _a = 2;
//};
//
//int main()
//{
//	B b;
//	b.Print(1);
//	return 0;
//}

//class A
//{
//public:
//	A(int a = 1)
//		: _a(a)
//	{}
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
//		return *this;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
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
//			A::operator=(bb);// ÇÐÆ¬
//			_b = bb._b;
//		}
//		return *this;
//	}
//
//	~B()
//	{
//		cout << "~B()" << endl;
//		A::~A();
//	}
//protected:
//	int _b;
//};
//
//int main()
//{
//	B b;
//	return 0;
//}


//class A
//{
//public:
//	A()
//	{
//		++cnt;
//	}
//
//	static int cnt;
//protected:
//	int _com;
//};
//
//int A::cnt = 0;
//
//class B : public A
//{
//public:
//protected:
//	int _com;
//};


class A
{
public:
	int _com;
};

class B : virtual public A
{
public:
};

class C : virtual public A
{
public:
};

class D : public B, public C
{
public:
};

int main()
{
	D d;
	d._com;
	d.B::_com;
	d.C::_com;
	return 0;
}