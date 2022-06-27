#pragma once
#include<iostream>
#include<assert.h>


using std::cout;
using std::cin;
using std::endl;


class Date
{
public:
	Date(int year = 0, int month = 0, int day = 1);
	void Print();
	Date& operator+=(int day);
	Date operator+(int day);

	Date& operator-=(int day);
	Date operator-(int day);

	int operator-(const Date& d);

	//++d
	Date& operator++();
	//d++
	Date operator++(int);
private:
	int _year;
	int _month;
	int _day;
};