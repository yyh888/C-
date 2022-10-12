#include "Test.h"


void test1()
{
	yyh::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	yyh::vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	v.resize(8);
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test2()
{
	yyh::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	yyh::vector<int> v2;
	v2 = v1;
	for (auto& e : v2)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test3()
{
	yyh::vector<int> v;
	v.insert(v.end(), 1);
	v.insert(v.end(), 2);
	v.insert(v.end(), 3);
	v.insert(v.end(), 4);
	//v.insert(v.end(), 5);
	// É¾³ıËùÓĞÅ¼Êı
	yyh::vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			it = v.erase(it);// ·ÀÖ¹ËõÈİ
		}
		else
		{
			it++;
		}
	}
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

int add(int& a, int& b)
{
	return a + b;
}

void test4()
{
	yyh::vector<string> v;
	v.push_back("1111111111111111");
	v.push_back("1111111111111111");
	v.push_back("1111111111111111");
	v.push_back("1111111111111111");
	v.push_back("1111111111111111");
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}



int main()
{
	test4();
	return 0;
}