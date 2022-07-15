#pragma once
#include<iostream>
// 只展开常用的防止命名冲突
using std::cin;
using std::cout;
using std::endl;


// 日期类声明
class Date
{
public:
	// 构造函数
	Date(int year = 0, int month = 1, int day = 1);
	// 打印年月日
	void Print();
	// 获取某年某月的天数
	int GetMonthDay(int year, int month);
	// 日期+=天数
	Date& operator+=(int day);
	// 日期+天数
	Date operator+(int day);
	// 日期-天数
	Date operator-(int day);
	// 日期-=天数
	Date& operator-=(int day);
	// 前置++
	Date& operator++();
	// 后置++
	Date operator++(int);
	// 后置--
	Date operator--(int);
	// 前置--
	Date& operator--();
	// >运算符重载
	bool operator>(const Date& d);
	// ==运算符重载
	bool operator==(const Date& d);
	// >=运算符重载
	inline bool operator >= (const Date& d);
	// <运算符重载
	bool operator < (const Date& d);
	// <=运算符重载
	bool operator <= (const Date& d);
	// !=运算符重载
	bool operator != (const Date& d);
	// 日期-日期 返回天数
	int operator-(const Date& d);
private:
	int _year;
	int _month;
	int _day;
};