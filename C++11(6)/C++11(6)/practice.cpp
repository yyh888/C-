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
//	// ������
//	func(function<int(int)>(f1), 2);
//	// �º�������
//	f2 ff;
//	func(function<int(int)>(ff), 2);
//	// lambda���ʽ
//	func(function<int(int)>([](int x)->int {return x * 2; }), 2);
//	return 0;
//}


//int main()
//{
//	// ��ͨ����
//	function<int(int)> fun1(f1);
//	cout << fun1(2) << endl;
//	// �º���
//	function<int(int)> fun2;
//	fun2 = f2();
//	cout << fun2(2) << endl;
//	// lambda���ʽ
//	function<int(int)> fun3;
//	fun3 = [](int x)->int {return 2 * x; };
//	cout << fun3(2) << endl;
//	// ��̬��Ա����ָ��
//	function<int(int)> fun4 = &f3::muli;
//	cout << fun4(2) << endl;
//	// �Ǿ�̬��Ա����ָ��
//	function<int(f3/*thisָ��*/, int)> fun5 = &f3::muld;
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
	// �Ǿ�̬��Ա����ָ��
	function<int(fun/*thisָ��*/, int)> fun1 = &fun::muld;
	cout << fun1(fun(), 2) << endl;
	// �󶨲���
	function<int(int)> fun2 = bind(&fun::muld, fun(), std::placeholders::_1);
	cout << fun2(2) << endl;
	return 0;
}
