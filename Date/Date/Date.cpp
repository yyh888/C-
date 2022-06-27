#include"Date.h"


inline int GetMonthDay(int year, int month)
{
	//��ֹƵ������
	static int dayArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = dayArray[month];
	//�����Ҷ���
	if ( month == 2 &&((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		day = 29;
	}
	return day;
}


Date::Date(int year, int month, int day)
{
	//������ںϷ���
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
		cout << "�Ƿ�����" << endl;
		assert(false);
	}
}

void Date::Print()
{
	cout << _year << "��" << _month << "��" << _day << "��" << endl;
}

Date& Date::operator+=(int day)
{
	_day += day;
	//���ڲ��Ϸ��ͽ�λʹ��Ϸ�
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
	//���� +=
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