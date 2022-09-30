#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//int main()
//{
//	vector<int> v1;// 无参数构造
//	vector<int> v2(5, 1);// 构造并初始化n个val
//	vector<int> v3(v1);// 拷贝构造
//	vector<int> v4(v1.begin(), v1.end());// 使用迭代器进行初始化构造
//	return 0;
//}

//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	vector<int>::iterator it = v.begin();// 正向访问
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	vector<int>::reverse_iterator rit = v.rbegin();// 逆向访问
//	while (rit != v.rend())
//	{
//		cout << *rit << " ";
//		rit++;
//	}
//	cout << endl;
//	for (int i = 0; i < v.size(); i++)// []访问
//	{
//		cout << v[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}


//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	cout << v.size() << endl;// 获取数据个数
//	cout << v.capacity() << endl;// 获取容量大小
//	cout << v.empty() << endl;// 判断是否为空
//	v.reserve(10);// 扩容
//	cout << "newsize:" << v.size() << endl;
//	cout << "newcapacity:" << v.capacity() << endl;
//	v.resize(10);// 扩容 + 初始化
//	cout << "newsize:" << v.size() << endl;
//	cout << "newcapacity:" << v.capacity() << endl;
//	return 0;
//}


//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	v.assign(4, 10);// 覆盖
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	return 0;
//}


//int main()
//{
//	vector<int> v;
//	v.push_back(5);
//	v.push_back(4);
//	v.push_back(3);
//	v.push_back(2);
//	v.push_back(7);
//	v.push_back(1);
//	v.push_back(6);
//	vector<int>::iterator it = find(v.begin(), v.end(), 6);// 查找
//	cout << *it << endl;
//	sort(v.begin(), v.end());// 排序
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	return 0;
//}


int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	v.reserve(10);
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	return 0;
}