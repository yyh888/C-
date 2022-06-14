#include<iostream>

using namespace std;

//int main()
//{
//	int a = 0;
//	int& b = a;
//	int& c = b;
//	c = 1;
//	cout << b << endl;
//	return 0;
//}





int main()
{
	const int a = 10;
	const int& b = a;
	int b = 0;
	const int& rb = b;
	int c = 10;
	double d = 1.11;
	const double& rc = c;
	return 0;
}