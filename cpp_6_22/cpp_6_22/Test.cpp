#include<iostream>


using namespace std;


//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	/*Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date()
//	{
//		_year = 0;
//		_month = 0;
//		_day = 1;
//	}*/
//
//	Date(int year = 0, int month = 0, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//class Stack
//{
//public:
//	void Init()
//	{
//		_a = nullptr;
//		_size = _capacity = 0;
//	}
//	void Print(int x)
//	{
//		_a = nullptr;
//		_size = 0;
//		_capacity = 0;
//	}
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//};
//
//
//int main()
//{
//	Date d1(2022, 6, 22);
//	d1.Print();
//	Date d2;
//	d2.Print();
//	Date d3(2021);
//	d3.Print();
//	Stack st;
//	st.Print(1);
//	return 0;
//}



//class A
//{
//public:
//	A(int a = 0)
//	{
//		_a = a;
//		cout << "A(int a = 0)" << endl;
//	}
//	void Print()
//	{
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//
//
//class Date
//{
//public:
//	/*Date()
//	{
//		_year = 0;
//		_month = 0;
//		_day = 1;
//	}*/
//
//	Date(int year = 0, int month = 0, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//		//_aa.Print();
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	A _aa;
//};
//
//
//
//int main()
//{
//	Date d1;
//	d1.Print();
//	return 0;
//}



//class Date
//{
//public:
//	~Date()
//	{
//		cout << "~Date()" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//class Stack
//{
//public:
//	Stack(int capacity = 4)
//	{
//		_a = (int*)malloc(sizeof(int) * capacity);
//		int _size = 0;
//		int _capacity = 4;
//	}
//	~Stack()
//	{
//		free(_a);
//		_size = _capacity = 0;
//	}
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//};
//
//
//
//int main()
//{
//	Date d1;
//	return 0;
//}





//class Date
//{
//public:
//	Date(int year = 0, int month = 0, int day = 0)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	bool Equal(Date d)
//	{
//		return _year == d._year
//			&& _month == d._month
//			&& _day == d._day;
//	}
////private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//bool operator==(Date x1, Date x2)
//{
//	return x1._year == x2._year
//		&& x1._month == x2._month
//		&& x1._day == x2._day;
//}
//
//
//
//int main()
//{
//	Date d1(2022, 6, 22);
//	Date d2(2022, 6, 22);
//	cout << d1.Equal(d2) << endl;
//	d1 == d2;
//	return 0;
//}




//class Date
//{
//public:
//	Date(int year = 0, int month = 0, int day = 0)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	bool Equal(Date d)
//	{
//		return _year == d._year
//			&& _month == d._month
//			&& _day == d._day;
//	}
//	bool operator==(Date x)
//	{
//		return _year == x._year
//			&& _month == x._month
//			&& _day == x._day;
//	}
//	private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//
//
//
//int main()
//{
//	Date d1(2022, 6, 22);
//	Date d2(2022, 6, 22);
//	cout << d1.Equal(d2) << endl;
//	d1.operator==(d2);//d1.opeartor==(&d1, d2)
//	cout << (d1 == d2) << endl;
//	return 0;
//}



class Array
{
public:
	Array()
	{
		for (int i = 0; i < 10; i++)
		{
			_a[i] = i * 10;
		}
	}

	int& operator[](size_t pos)
	{
		return _a[pos];
	}
private:
	int _a[10];
};


int main()
{
	Array ay;
	cout << ay[1] << endl;//ay.operator[](&ay, 1)
	return 0;
}