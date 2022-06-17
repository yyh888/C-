#include<iostream>


using namespace std;


//struct A
//{
//	int a;
//};
//
//
//void Fun(A a)
//{
//
//}
//
//void Fun1(A& a)
//{
//
//}
//
//int main()
//{
//	A a;
//	A& aa = a;
//	Fun(a);
//	Fun1(aa);
//	return 0;
//}

union aa
{
	float x, y;
	char c[6];
};


struct st
{
	union aa v;
	//float w[5];
	//double ave;
}w;

union {
	char c;
	char i[4];
}z;


int main()
{
	int sz = sizeof(w);
	z.i[0] = 0x39;
	z.i[1] = 0x36;
	printf("%c\n", z.c);
	cout << sz << endl;
	return 0;
}