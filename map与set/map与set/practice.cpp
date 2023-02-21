#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

void test_set()
{
	// 默认构造
	set<int> s1;
	// 迭代器区间构造
	int a[] = { 1, 2, 3, 4 };
	set<int> s2(a, a + 4);
	// 拷贝构造（深拷贝）
	set<int> s3(s2);

	for (int e : s2) cout << e << " ";
	cout << endl;
	for (int e : s3) cout << e << " ";
	cout << endl;
}

void test1()
{
	set<int, greater<int>> s;// 排序+去重
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(1);
	s.insert(3);
	s.insert(4);
	// 正向迭代器
	set<int>::iterator it1 = s.begin();
	while (it1 != s.end())
	{
		cout << *it1++ << " ";
	}
	cout << endl;
	// 反向迭代器
	set<int>::reverse_iterator it2 = s.rbegin();
	while (it2 != s.rend())
	{
		cout << *it2++ << " ";
	}
	cout << endl;
}

void test2()
{
	set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(5);
	cout << s.count(2) << endl;
	cout << s.count(6) << endl;
}

void test3()
{
	multiset<int> ms;
	ms.insert(1);
	ms.insert(1);
	ms.insert(2);
	ms.insert(3);
	ms.insert(4);
	for (auto& e : ms)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << "count(1): " << ms.count(1) << endl;
}

void test4()
{
	map<string, int> m;
	m.insert(pair<string, int>("a", 1));// 匿名对象
	m.insert(make_pair("b", 2));// 简化写法
	m.insert(make_pair("c", 2));
	m.insert(make_pair("d", 2));
	map<string, int>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << (*it).first << "->" << (*it).second << endl;
		it++;
	}
}

int main()
{
	multimap<string, int> mm;
	string arr[] = { "北京", "武汉", "广州", "上海", "北京", "北京", "广州",
	"上海", "上海" };
	for (auto& e : arr)
	{
		map<string, int>::iterator fd = mm.find(e);
		if (fd == mm.end())
		{
			mm.insert(make_pair(e, 1));
		}
		else
		{
			fd->second++;
		}
	}
	for (auto& e : mm)
	{
		cout << e.first << "->" << e.second << endl;
	}
	return 0;
}

//int main()
//{
//	map<string, int> m;
//	// 插入
//	m["广西"];
//	m["广东"] = 1;
//	m.insert(make_pair("广东", 2));// 插入失败
//	for (auto& e : m)
//	{
//		cout << e.first << "->" << e.second << endl;
//	}
//	return 0;
//}


//int main()
//{
//	string arr[] = { "北京", "武汉", "广州", "上海", "北京", "北京", "广州",
//	"上海", "上海" };
//	map<string, int> cnt;
//	for (auto& e : arr)
//	{
//		cnt[e]++;
//	}
//	for (auto& e : cnt)
//	{
//		cout << e.first << "->" << e.second << endl;
//	}
//	return 0;
//}

//int main()
//{
//	string arr[] = { "北京", "武汉", "广州", "上海", "北京", "北京", "广州",
//	"上海", "上海" };
//	map<string, int> cnt;
//	for (auto& e : arr)
//	{
//		map<string, int>::iterator fd = cnt.find(e);
//		if (fd == cnt.end())
//		{
//			cnt.insert(make_pair(e, 1));
//		}
//		else
//		{
//			fd->second++;
//		}
//	}
//	for (auto& e : cnt)
//	{
//		cout << e.first << "->" << e.second << endl;
//	}
//	return 0;
//}
