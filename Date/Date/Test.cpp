#include"Date.h"



void Test1()
{
	Date d(2022, 6, 26);
	d.Print();
	d -= 365;
	d.Print();
	d++;
	d.Print();
	++d;
	d.Print();
}

int main()
{
	/*Date d(2022, 6, 26);
	d.Print();
	d += 36;
	d.Print();
	d + 10;
	d.Print();
	Date d1 = d + 10;
	d1.Print();*/
	Test1();
	return 0;
}