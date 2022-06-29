#include<iostream>

using namespace std;

class Date
{
public:
	Date(int year = 0, int month = 0, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	bool operator==(const Date& d)const
	{
		return (_year == d._year)
			&& (_month == d._month)
			&& (_day == d._day);
	}

	void Print()const
	{
		cout << _year << "Äê" << _month << "ÔÂ" << _day << "ÈÕ" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2022, 6, 29);
	Date d2(2022, 5, 29);
	cout << (d1 == d2) << endl;
	d1.Print();
	d2.Print();
	return 0;
}