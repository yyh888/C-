#include<iostream>
#include<string>

using namespace std;

//class A
//{
//public:
//	A(int x)
//	{
//		cout << "A()" << endl;
//		_a = x;
//	}
//private:
//	int _a;
//};
//
//
//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, n(10)
//		, _aa(10)
//	{
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "年" << _month << "月" << _day << "日";
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	const int n;
//	A _aa;
//};
//
//
//int main()
//{
//	Date d1(2022, 7, 4);
//	d1.Print();
//	A _aa = 2;
//	return 0;
//}




//class A
//{
//public:
//	A(int a = 1)
//		: _a(a)
//	{}
//	void P()
//	{
//		cout << "P()" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A aa1(1);
//    //A aa2 = 2;
//	/*string s1("hello world");
//	string s2 = "hello world";*/
//	A aa2 = 3;
//	A().P();
//	return 0;
//}



//class A
//{
//public:
//	A()
//	{
//		_n++;
//	}
//	A(const A& a)
//	{
//		_n++;
//	}
//	void f()
//	{
//		GetN();
//	}
//	//不能访问非静态成员
//	static int GetN()
//	{
//		return _n;
//	}
//private:
//	static int _n;
//	int _a;
//};
//
//int A::_n = 0;
//
//
//int main()
//{
//	A a;
//	A a1;
//	A a2;
//	cout << a1.GetN() << endl;
//	cout << a2.GetN() << endl;
//	cout << A().GetN() << endl;
//	cout << A::GetN() << endl;
//
//	return 0;
//}




//class A
//{
//public:
//	void Print()
//	{
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//
//
//class B
//{
//public:
//
//private:
//};