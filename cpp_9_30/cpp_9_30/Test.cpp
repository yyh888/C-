#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//int main()
//{
//	vector<int> v1;// �޲�������
//	vector<int> v2(5, 1);// ���첢��ʼ��n��val
//	vector<int> v3(v1);// ��������
//	vector<int> v4(v1.begin(), v1.end());// ʹ�õ��������г�ʼ������
//	return 0;
//}

//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	vector<int>::iterator it = v.begin();// �������
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	vector<int>::reverse_iterator rit = v.rbegin();// �������
//	while (rit != v.rend())
//	{
//		cout << *rit << " ";
//		rit++;
//	}
//	cout << endl;
//	for (int i = 0; i < v.size(); i++)// []����
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
//	cout << v.size() << endl;// ��ȡ���ݸ���
//	cout << v.capacity() << endl;// ��ȡ������С
//	cout << v.empty() << endl;// �ж��Ƿ�Ϊ��
//	v.reserve(10);// ����
//	cout << "newsize:" << v.size() << endl;
//	cout << "newcapacity:" << v.capacity() << endl;
//	v.resize(10);// ���� + ��ʼ��
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
//	v.assign(4, 10);// ����
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
//	vector<int>::iterator it = find(v.begin(), v.end(), 6);// ����
//	cout << *it << endl;
//	sort(v.begin(), v.end());// ����
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