#include <iostream>
#include <string>
using namespace std;


//int main()
//{
//	char str[5] = "中国";
//	cout << str << endl;
//	str[3] = -7;
//	cout << str << endl;
//	return 0;
//}


//int main()
//{
//	string s1("abcdefg");
//	string s2(s1, 0, 3);
//	cout << s2 << endl;
//	return 0;
//}


//int main()
//{
//	string s1("abcdefg");
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		cout << s1[i] << " ";
//	}
//	cout << endl;
//	//迭代器
//	string::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	//反向迭代器
//	string::const_reverse_iterator rit = s1.crbegin();
//	while (rit != s1.crend())
//	{
//		cout << *rit << " ";
//		rit++;
//	}
//	cout << endl;
//	//反向迭代器
//	for (auto e : s1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}



int main()
{
	string s1("a");
	s1.push_back('b');
	s1.push_back('c');
	s1.push_back('d');
	s1.push_back('e');
	s1.append("wwwwww");
	s1 += "aaaaaaaaaaa";
	s1.insert(0, "2");
	s1.insert(0, "2");
	s1.insert(0, "2");
	cout << s1 << endl;
	s1.erase(0, 1);
	cout << s1 << endl;
	s1.erase(5, 1000);
	cout << s1 << endl;
	return 0;
}