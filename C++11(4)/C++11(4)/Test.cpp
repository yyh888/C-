#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;

//struct gift
//{
//	std::string _name;// ����
//	int _vol;// ���
//	double _val;// ��ֵ
//
//	gift(const char* name, int vol, double val)
//		: _name(name)
//		, _vol(vol)
//		, _val(val)
//	{}
//};
//
//struct CmpNameLess
//{
//	bool operator()(const gift& g1, const gift& g2)
//	{
//		return g1._name < g2._name;
//	}
//};
//
//struct CmpVolLess
//{
//	bool operator()(const gift& g1, const gift& g2)
//	{
//		return g1._vol < g2._vol;
//	}
//};
//
//struct CmpValLess
//{
//	bool operator()(const gift& g1, const gift& g2)
//	{
//		return g1._val < g2._val;
//	}
//};
//
//
//int main()
//{
//	std::vector<gift> v = { {"ƻ��", 10, 20.0}, {"����", 15, 12.8}, {"�㽶", 11, 10.2} };
//	//sort(v.begin(), v.end(), CmpNameLess());
//	sort(v.begin(), v.end(), [](const gift& g1, const gift& g2){
//		return g1._name < g2._name; });
//	return 0;
//}

//int main()
//{
//	// [](int x, int y)->bool {return x < y; };
//	auto cmp = [](int x, int y){return x < y; };
//	cout << cmp(1, 2) << endl;
//	return 0;
//}

//int main()
//{
//	int a = 1, b = 2;
//	auto add = [a](int x) {return x + a; };
//	cout << add(b);
//	return 0;
//}

//int main()
//{
//	int a = 1, b = 2;
//	auto Swap = [&]()
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	};
//	Swap();
//	cout << a << " " << b << endl;
//	return 0;
//}

//int main()
//{
//	int a = 1, b = 2;
//	auto fun = [=, &b]() {};
//	return 0;
//}

struct Add
{
	int operator()(int x, int y)
	{
		return x + y;
	}
};

int main()
{
	// ��������
	Add sum1;
	sum1(1, 2);
	// lambda���ʽ
	auto sum2 = [](int a, int b) {return a + b; };
	sum2(1, 2);
	return 0;
}