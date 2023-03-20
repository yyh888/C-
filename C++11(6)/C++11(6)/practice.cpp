#include <iostream>
#include <functional>
using namespace std;



//int Plus(int a, int b)
//{
//	return a - b;
//}
//
//int main()
//{
//	function<int(int, int)> fun1 = bind(Plus, placeholders::_1, placeholders::_2);
//	cout << fun1(1, 2) << endl;
//	function<int(int, int)> fun2 = bind(Plus, placeholders::_2, placeholders::_1);
//	cout << fun2(1, 2) << endl;
//	return 0;
//}





//template <class F, class T>
//T func(F fun, T val)
//{
//	static int cnt = 1;
//	cout << "cnt: " << cnt++ << endl;
//	cout << "&cnt: " << &cnt << endl;
//	return fun(val);
//}
//
//int f1(int x)
//{
//	return x * 2;
//}
//
//struct f2
//{
//	int operator()(int x)
//	{
//		return x * 2;
//	}
//};
//
//class f3
//{
//public:
//	static int muli(int x)
//	{
//		return x * 2;
//	}
//
//	double muld(double x)
//	{
//		return x * 2;
//	}
//};
//
//
//int main()
//{
//	// 函数名
//	func(function<int(int)>(f1), 2);
//	// 仿函数对象
//	f2 ff;
//	func(function<int(int)>(ff), 2);
//	// lambda表达式
//	func(function<int(int)>([](int x)->int {return x * 2; }), 2);
//	return 0;
//}


//int main()
//{
//	// 普通函数
//	function<int(int)> fun1(f1);
//	cout << fun1(2) << endl;
//	// 仿函数
//	function<int(int)> fun2;
//	fun2 = f2();
//	cout << fun2(2) << endl;
//	// lambda表达式
//	function<int(int)> fun3;
//	fun3 = [](int x)->int {return 2 * x; };
//	cout << fun3(2) << endl;
//	// 静态成员函数指针
//	function<int(int)> fun4 = &f3::muli;
//	cout << fun4(2) << endl;
//	// 非静态成员函数指针
//	function<int(f3/*this指针*/, int)> fun5 = &f3::muld;
//	cout << fun5(f3(), 2) << endl;
//	f3 ff;
//	function<int(int)> fun6 = [&ff](int x)->double {return ff.muld(x); };
//	cout << fun6(2) << endl;
//	return 0;
//}




class fun
{
public:
	static int muli(int x)
	{
		return x * 2;
	}

	double muld(double x)
	{
		return x * 2;
	}
};

int main()
{
	// 非静态成员函数指针
	function<int(fun/*this指针*/, int)> fun1 = &fun::muld;
	cout << fun1(fun(), 2) << endl;
	// 绑定参数
	function<int(int)> fun2 = bind(&fun::muld, fun(), std::placeholders::_1);
	cout << fun2(2) << endl;
	return 0;
}
