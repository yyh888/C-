#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void test1()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	vector<int>::iterator ret = find(v.begin(), v.end(), 3);
	cout << v.capacity() << endl;
	if (ret != v.end())
	{
		cout << "ур╣╫ак" << endl;
	}
	v.insert(v.begin(), 100);
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	v.erase(v.begin());
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	v.clear();
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << v.capacity() << endl;
}

int main()
{
	test1();
	return 0;
}