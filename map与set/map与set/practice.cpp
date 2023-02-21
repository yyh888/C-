#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

void test_set()
{
	// Ĭ�Ϲ���
	set<int> s1;
	// ���������乹��
	int a[] = { 1, 2, 3, 4 };
	set<int> s2(a, a + 4);
	// �������죨�����
	set<int> s3(s2);

	for (int e : s2) cout << e << " ";
	cout << endl;
	for (int e : s3) cout << e << " ";
	cout << endl;
}

void test1()
{
	set<int, greater<int>> s;// ����+ȥ��
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(1);
	s.insert(3);
	s.insert(4);
	// ���������
	set<int>::iterator it1 = s.begin();
	while (it1 != s.end())
	{
		cout << *it1++ << " ";
	}
	cout << endl;
	// ���������
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
	m.insert(pair<string, int>("a", 1));// ��������
	m.insert(make_pair("b", 2));// ��д��
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
	string arr[] = { "����", "�人", "����", "�Ϻ�", "����", "����", "����",
	"�Ϻ�", "�Ϻ�" };
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
//	// ����
//	m["����"];
//	m["�㶫"] = 1;
//	m.insert(make_pair("�㶫", 2));// ����ʧ��
//	for (auto& e : m)
//	{
//		cout << e.first << "->" << e.second << endl;
//	}
//	return 0;
//}


//int main()
//{
//	string arr[] = { "����", "�人", "����", "�Ϻ�", "����", "����", "����",
//	"�Ϻ�", "�Ϻ�" };
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
//	string arr[] = { "����", "�人", "����", "�Ϻ�", "����", "����", "����",
//	"�Ϻ�", "�Ϻ�" };
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
