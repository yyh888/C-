#include <iostream>
#include <string>
using namespace std;
//int main()
//{
//	char str[] = "hello cpp";
//	return 0;
//}


//int main()
//{
//	string s1;// 1
//	string s2("hello string");// 2
//	string s3(3, 'c');// 3
//	string s4(s3);// 4
//	cout << s3 << endl;
//	return 0;
//}


//int main()
//{
//	string s1("abcdef");
//	cout << s1.size() << endl;// 1
//	cout << s1.length() << endl;// 2
//	cout << s1.capacity() << endl;// 3
//	cout << s1.empty() << endl;// 4
//	s1.clear();// 5
//	cout << s1 << endl;
//	return 0;
//}


int main()
{
	string s1("abcdefghi");
	cout << s1[2] << endl;// 1
	//µü´úÆ÷
	string::iterator it = s1.begin();// 2
	//auto it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	//·¶Î§for
	for (auto& e : s1)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}



//int main()
//{
//	string s1;
//	s1.push_back('c');
//	cout << s1 << endl;// 1
//	s1.append("pp");// 2
//	cout << s1 << endl;
//	s1 += " hello";// 3
//	cout << s1 << endl;
//	const char* str = s1.c_str();// 4
//	cout << str << endl;
//	return 0;
//}