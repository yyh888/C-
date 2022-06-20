#include<iostream>


using namespace std;

//class Date
//{
//public:
//	void DateInit(int year, int month, int day)
//	{
//		this->_year = year;
//		this->_month = month;
//		_day = day;
//		cout << "this:" << this << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	Date d1;
//	cout << "d1:" << &d1 << endl;
//	//Date d2;
//	d1.DateInit(2022, 6, 20);
//	return 0;
//}


class A
{
public:
	void Printf()
	{
		cout << _a << endl;
	}
	
	void Show()
	{
		cout << "show()" << endl;
	}
private:
	int _a;
};


int main()
{
	//A* p = nullptr;
	A a;
	a.Printf();
	a.Show();
	return 0;
}