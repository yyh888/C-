#include"Date.h"


inline int GetMonthDay(int year, int month)
{
	//防止频繁开辟
	static int dayArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = dayArray[month];
	//闰年且二月
	if ( month == 2 &&((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		day = 29;
	}
	return day;
}


Date::Date(int year, int month, int day)
{
	//检查日期合法性
	if (year >= 0 
		&& month > 0 && month < 13
		&& day > 0 && day <= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "非法日期" << endl;
		assert(false);
	}
}

void Date::Print()
{
	cout << _year << "年" << _month << "月" << _day << "日" << endl;
}

Date& Date::operator+=(int day)
{
	_day += day;
	//日期不合法就进位使其合法
	while (_day > GetMonthDay(_year, _month))
	{
		_month++;
		if (_month > 12)
		{
			_year++;
			_month = 1;
		}
		_day -= GetMonthDay(_year, _month);
	}
	return *this;
}


Date Date::operator+(int day)
{
	Date ret(*this);
	//复用 +=
	ret += day;
	return ret;
}


Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day <= 0)
	{
		if ((_month--) < 0)
		{
			_year--;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}



Date Date::operator-(int day)
{
	Date ret(*this);
	ret -= day;
	return ret;
}


//++d
Date& Date::operator++()
{
	_day++;
	if (_day > GetMonthDay(_year, _month))
	{
		_day = 1;
		_month++;
		if (_month > 12)
		{
			_month = 1;
			_year++;
		}
	}
	return *this;
}



Date Date::operator++(int)
{
	Date ret(*this);
	_day++;
	if (_day > GetMonthDay(_year, _month))
	{
		_day = 1;
		_month++;
		if (_month > 12)
		{
			_month = 1;
			_year++;
		}
	}
	return ret;
}