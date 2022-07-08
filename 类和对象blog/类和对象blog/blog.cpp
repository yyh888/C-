#include<iostream>

using namespace std;



//class className
//{
//	// 类体：由成员函数和成员变量组成
//}; // 一定要注意后面的分号



//class Person
//{
//public:
//	//打印基本信息
//	void Print()
//	{
//		cout << _name << "-" << _sex << "-" << _age << endl;
//	}
//private:
//	char* _name;
//	char* _sex;
//	int _age;
//};


//.h
//class Person
//{
//public:
//	//打印基本信息
//	void Print();
//public:
//	char* _name;
//	char* _sex;
//	int _age;
//};
////.cpp
//void Person::Print()
//{
//	cout << _name << "-" << _sex << "-" << _age << endl;
//}

//int main()
//{
//	Person yyh;
//	yyh.Print();
//	return 0;
//}



//class Date
//{
//public:
//	void Print()
//	{
//		cout << _year << _month << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	Date d;
//	cout << sizeof(d) << endl;
//	return 0;
//}


//class A
//{
//	//类中仅有成员函数
//public:
//	void f() 
//	{}
//};
//
//class B
//{};
//
//int main()
//{
//	A a;
//	B b;
//	B b1;
//	B b2;
//	cout << sizeof(a) << endl;
//	cout << sizeof(b) << endl;
//	return 0;
//}


//class Date
//{
//public:
//	//Init(Date* this, int year, int month, int day)
//	void Init(int year, int month, int day)
//	{
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	 }
//private:
//	int _year;
//	int _month; 
//	int _day;
//};
//
//
//int main()
//{
//	Date d1;
//	d1.Init(2022, 1, 1);//d1.Init(&d1, 2022, 1, 1)
//	Date d2;
//	d2.Init(2022, 1, 2);//d2.Init(&d2, 2022, 1, 2)
//	return 0;
//}



class A
{
public:
	void PrintA()
	{
		cout << _a << endl;
	}

	void Show()
	{
		cout << "Show()" << endl;
	}
private:
	int _a;
};

int main()
{
	A* p = nullptr;
	p->PrintA();//p->PrintA(&p)
	p->Show();
}