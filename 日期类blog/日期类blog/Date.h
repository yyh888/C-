#pragma once
#include<iostream>
// ֻչ�����õķ�ֹ������ͻ
using std::cin;
using std::cout;
using std::endl;


// ����������
class Date
{
public:
	// ���캯��
	Date(int year = 0, int month = 1, int day = 1);
	// ��ӡ������
	void Print();
	// ��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month);
	// ����+=����
	Date& operator+=(int day);
	// ����+����
	Date operator+(int day);
	// ����-����
	Date operator-(int day);
	// ����-=����
	Date& operator-=(int day);
	// ǰ��++
	Date& operator++();
	// ����++
	Date operator++(int);
	// ����--
	Date operator--(int);
	// ǰ��--
	Date& operator--();
	// >���������
	bool operator>(const Date& d);
	// ==���������
	bool operator==(const Date& d);
	// >=���������
	inline bool operator >= (const Date& d);
	// <���������
	bool operator < (const Date& d);
	// <=���������
	bool operator <= (const Date& d);
	// !=���������
	bool operator != (const Date& d);
	// ����-���� ��������
	int operator-(const Date& d);
private:
	int _year;
	int _month;
	int _day;
};