#include "SmartPtr.h"
#include <memory>


int main()
{
	test();
	return 0;
}







//double div()
//{
//	double a, b;
//	cin >> a >> b;
//	if (b == 0)
//	{
//		throw "��0����";
//	}
//	return a / b;
//}
//
//void fun()
//{
//	int* p1 = new int[10];
//	SmartPtr<int> sp1(p1);
//	SmartPtr<int> sp2(new int[15]);
//	cout << div() << endl;
//}
//
//int main()
//{
//	try
//	{
//		fun();
//	}
//	catch (const char* errstr)
//	{
//		cout << errstr << endl;
//	}
//	catch (...)
//	{
//		cout << "δ֪����" << endl;
//	}
//	return 0;
//}