#include"Date.h"



void Test1()
{
	Date d(2021, 5, 27);
	d.Print();
	d -= 120;
	d.Print();
}


void Test2()
{
	Date d1(2022, 7, 31);
	Date d2(2022, 6, 28);
	cout << d1 - d2 << endl;
	cout << d2 - d1 << endl;
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
	//Test1();
	//Test2();
	Date d(1941, 12, 11);
	d += 100;
	d.Print();
	return 0;
}