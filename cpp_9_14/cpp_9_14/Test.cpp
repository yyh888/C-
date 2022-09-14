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


//int main()
//{
//	string s1("abcdefghi");
//	cout << s1[2] << endl;// 1
//	//µü´úÆ÷
//	string::iterator it = s1.begin();// 2
//	//auto it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	//·¶Î§for
//	for (auto& e : s1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}



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


//int main()
//{
//	string s1;
//	cout << s1.capacity() << endl;
//	s1.reserve(1000);
//	cout << s1.capacity() << endl;
//	string s2("abc");
//	s2.resize(10, 'f');
//	cout << s2 << endl;
//	return 0;
//}


//int main()
//{
//	string s1("test.txt");
//	size_t pos = s1.find('.');// 5
//	string s2(s1, pos);
//	cout << s2 << endl;
//	string s3 = s1.substr(0, pos);// 7
//	cout << s3 << endl;
//	return 0;
//}


//void Fun(int a, int b, int c = 2)
//{
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//}
//
//int main()
//{
//	Fun(100, 200);
//	return 0;
//}


int main()
{
	string s1("hello ");
	string s2 = s1 + "cpp";// 1
	cout << s2 << endl;
	string s3;
	cin >> s3;// 2
	cout << s3 << endl;// 3
	string s4;
	getline(cin, s4);// 4
	cout << s4 << endl;
	return 0;
}


//namespace yyh
//{
//	class string
//	{
//	public:
//		string(const char* str)
//			: _str(new char[strlen(str + 1)])
//		{
//			strcpy(_str, str);
//		}
//	private:
//		char* _str;
//	};
//}