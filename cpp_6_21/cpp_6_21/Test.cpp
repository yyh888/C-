#include<iostream>

using namespace std;



class A
{
public:
	A(int a = 0)
	{
		cout << "A(int a = 0)" << endl;
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
	/*void Init(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date()
	{
		_year = 0;
		_month = 0;
		_day = 1;
	}*/
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
		_aa.Print();
	}
private:
	int _year;
	int _month;
	int _day;
	A _aa;
};


//class Stack
//{
//public:
//	void Init()
//	{
//		_a = nullptr;
//		_size = _capacity = 0;
//	}
//	Stack()
//	{
//		_a = nullptr;
//		_size = _capacity = 0;
//	}
//
//	Stack(int capacity)
//	{
//		_a = nullptr;
//		_size = 0;
//		_capacity = capacity;
//	}
//	void Push()
//	{
//
//	}
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//};

int main()
{
	/*Date d(2022, 6, 21);
	d.Print();
	Date d2;
	d2.Print();
	Stack s;
	s.Push();*/
	Date d;
	d.Print();
	return 0;
}