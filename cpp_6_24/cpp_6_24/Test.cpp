#include<iostream>


using namespace std;


class A
{
public:
	A(int a = 10)
	{
		_a = a;
	}

	void Print()
	{
		cout << _a << endl;
	}
private:
	int _a;
};


class Date
{
public:
	Date(int year = 0, int month = 0, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
		_aa.Print();
	}

	//Date& operator=(const Date& d)
	//{
	//	if (this != &d)//不是自己给自己赋值
	//	{
	//		_year = d._year;
	//		_month = d._month;
	//		_day = d._day;
	//	}
	//	return *this;
	//}

private:
	int _year;
	int _month;
	int _day;
	A _aa;
};


int main()
{
	Date d1(2022, 6, 24);
	d1.Print();
	Date d2, d3;
	d3 = d2 = d1;
	d2.Print();
	d3.Print();
	return 0;
}