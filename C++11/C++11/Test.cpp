#include <iostream>
#include <list>
#include <vector>
#include <array>
#include < forward_list >

//struct A
//{
//	int _a;
//	double _b;
//};
//
//int main()
//{
//	/*A aa{ 1, 1.1 };
//	cout << aa._a << " " << aa._b << endl;*/
//	A* ptr = new A[2]{ {1, 1.1}, {2, 2.2} };
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//		std::cout << "Date(int year, int month, int day)" << std::endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(1, 2, 3);
//	Date d2{1, 2, 3};
//	return 0;
//}

//int main()
//{
//	std::vector<int> v={ 1, 2, 3, 4, 5 }; // 列表初始化
//	std::list<int> lt{ 1, 2, 3, 4, 5, 6 };// 列表初始化
//	for (auto& e : v)
//	{
//		std::cout << e << " ";
//	}
//	std::cout << "\n";
//	for (auto& e : lt)
//	{
//		std::cout << e << " ";
//	}
//	std::cout << "\n";
//	return 0;
//}

//struct Test
//{
//	int _a;
//	double _b;
//};
//
//int main()
//{
//	Test tOld = { 1, 1.1 };
//	Test tNew{ 2, 2.2 };// 列表初始化
//
//	int a = 1;
//	int b = { 1 };// 列表初始化
//	int c{ 1 };// 列表初始化
//
//	int arr1[] = { 1,2,3 };
//	int arr2[]{ 1,2,3 };// 列表初始化
//
//	int* ptr1 = new int[] {1, 2, 3};
//	Test* ptr2 = new Test[]{ {1, 1.1}, {2, 2.2} };
//	return 0;
//}

//int main()
//{
//	auto tmp = { 1, 2, 3, 4 };
//	std::cout << typeid(tmp).name() << std::endl;
//	return 0;
//}

//double foo()
//{
//	return 1.1;
//}
//
////struct Test
////{
////	auto a = 1;// error
////};
////
////void func(auto a) {}
//
//int main()
//{
//	// 内置类型
//	int a = 1;
//	auto b = a;// int
//	auto c = foo();// double
//
//	// 自定义类型
//	Test test;
//	auto ret = test;// struct Test
//	//auto a;// error
//	//a = 10;
//	return 0;
//}


//int main()
//{
//	//auto arr[] = { 1, 2, 3 };// error
//	std::vector<auto> v; // error
//	return 0;
//}

//int main()
//{
//	int x = 0;
//	decltype(x) a = 10;// int
//	double y = 0.0;
//	decltype(x + y) b;// double
//	return 0;
//}

//int main()
//{
//	int a[] = { 1, 2, 3, 4, 5, 6 };
//	for (int& e : a)
//	{
//		std::cout << e << " ";
//	}
//	std::cout << '\n';
//	return 0;
//}

//int main()
//{
//	int a1[10];
//	a1[22];// 不报错
//	std::array<int, 10> a2;
//	a2[22];// 报错
//	return 0;
//}

int main()
{
	std::vector<int> a = { 1, 2, 3, 4, 5, 6 };
	std::forward_list<int> lt(a.begin(), a.end());
	for (auto& e : lt)
	{
		std::cout << e << " ";
	}
	std::cout << '\n';
	return 0;
}