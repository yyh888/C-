#include"Date.h"


void Test1()
{
	Date d1(2022, 12, 31);
	++d1;
	d1.Print();
}


int main()
{
	Test1();
	return 0;
}