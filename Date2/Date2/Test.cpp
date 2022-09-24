class Date

{

public:

	// ��ȡĳ��ĳ�µ�����

	int GetMonthDay(int year, int month)
	{
		static int Day[] = { 0, 31, 28, 31, 30, 31, 30 ,31, 31, 30, 31, 30, 31 };
		int day = Day[month];
		if (month == 2 && ((year % 4 == 0) && (year % 100 != 0)) || (year % 400) == 0)
		{
			day++;
		}
		return day;
	}


	// ȫȱʡ�Ĺ��캯��

	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}



	// �������캯��
  // d2(d1)
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}



	// ��ֵ���������

  // d2 = d3 -> d2.operator=(&d2, d3)

	Date& operator=(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}



	// ��������

	~Date()
	{
		_year = 0;
		_month = 0;
		_day = 0;
	}



	// ����+=����

	Date& operator+=(int day)
	{
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month > 12)
			{
				_year++;
				_month = 1;
			}
		}
		return *this;
	}



	// ����+����

	Date operator+(int day)
	{
		Date tmp(*this);
		tmp += day;
		return tmp;
	}



	// ����-����

	Date operator-(int day)
	{
		Date tmp(*this);
		tmp -= day;
		return tmp;
	}



	// ����-=����

	Date& operator-=(int day)
	{
		_day -= day;
		while (_day < 1)
		{
			_month--;
			if (_month == 0)
			{
				_year--;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}



	// ǰ��++

	Date& operator++()
	{
		*this += 1;
		return *this;
	}



	// ����++

	Date operator++(int)
	{
		Date tmp(*this);
		*this += 1;
		return tmp;
	}



	// ����--

	Date operator--(int)
	{
		Date tmp(*this);
		*this -= 1;
		return tmp;
	}



	// ǰ��--

	Date& operator--()
	{
		*this -= 1;
		return *this;
	}



	// >���������

	bool operator>(const Date& d)
	{
		if (_year > d._year)
		{
			return true;
		}
		else if(_year == d._year)
		{
			if (_month > d._month)
			{
				return true;
			}
			else if (_month == d._month)
			{
				if (_day > d._day)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}



	// ==���������

	bool operator==(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}



	// >=���������

	bool operator >= (const Date& d)
	{
		return (*this > d) || (*this == d);
	}



	// <���������

	bool operator < (const Date& d)
	{
		return !(*this >= d);
	}



	// <=���������

	bool operator <= (const Date& d)
	{
		return !(*this > d);
	}



	// !=���������

	bool operator != (const Date& d)
	{
		return !(*this == d);
	}



	// ����-���� ��������

	int operator-(const Date& d)
	{
		int flag = 1;
		Date max = *this, min = d;
		if (max < min)
		{
			min = *this;
			max = d;
			flag = -1;
		}
		int day = 0;
		while (min != max)
		{
			min++;
			day++;
		}
		return flag * day;
	}

private:

	int _year;

	int _month;

	int _day;

};


int main()
{
	Date d1(2022, 1, 1);
	d1 += 365;
	Date d3 = d1 + 365;
	d3 -= 366;
	return 0;
}