#include <iostream>
#include <vector>
#include <string>
using namespace std;

void test1()
{
	vector<int> v1;
	vector<int> v2(10, 8);
	vector<int> v3(++v2.begin(), --v2.end());
	vector<int> v4(v3);

	string s1("hello vector");
	vector<char> v5(s1.begin(), s1.end());
}

void test2()
{
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	for (size_t i = 0; i < v.size(); i++)
	{
		v[i] += 1;
		cout << v[i] << " ";
	}
	cout << endl;
	
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		*it += 1;
		cout << *it << " ";
		it++;
	}
	cout << endl;

	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	//test1();
	test2();
	return 0;
}