#include<iostream>

using namespace std;

class Date
{
	friend ostream& operator<<(ostream& out, const Date d);
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
		cout << _year << "年" << _month << "月" << _day << "日" << endl;
	}


	Date* operator&()
	{
		return this;
	}
	const Date* operator&()const
	{
		return this;
	}

private:
	int _year;
	int _month;
	int _day;
};


ostream& operator<<(ostream& out, const Date d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
	return out;
}


int main()
{
	Date d1(2022, 6, 29);
	Date d2(2022, 5, 29);
	/*cout << (d1 == d2) << endl;
	d1.Print();
	d2.Print();*/
	cout << d1 << d2;
	return 0;
}



