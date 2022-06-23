#include<iostream>


using namespace std;


//class B 
//{
//public:
//	/*B(int p = 0)
//	{
//		_p = p;
//	}*/
//private:
//	int _p;
//};
//
//
//class A
//{
//public:
//	void Print()
//	{
//		cout << _a << " " << _b << " " << _c << endl;
//	}
//private:
//	int _a;
//	int _b;
//	int _c;
//	B _p;
//};
//
//
//int main()
//{
//	A a;
//	return 0;
//}



class Date
{
public:
	Date(int year = 0, int month = 0, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};


//void f1(Date d)
//{
//
//}
//
//void f2(Date& d)
//{
//
//}


int main()
{
	Date d1(2022, 6, 23);
	d1.Print();
	Date d4;
	d4 = d1;
	d4.Print();
	/*f1(d1);
	f2(d1);*/
	return 0;
}