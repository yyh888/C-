#include "string.h"

void test1()
{
	yyh::string s1("hello cpp");
	yyh::string s2;
	cout << s2.c_str() << endl;
	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;
	yyh::string::const_iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	for (auto e : s1)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test2()
{
	yyh::string s1("abcdefghijklmn");
	s1.yyh::string::append("opqrstuwdxyz");
	cout << s1.c_str() << endl;
}

void test3()
{
	yyh::string s1;
	s1 += 'd';
	cout << s1.c_str() << endl;
	s1 += "trttttt";
	cout << s1.c_str() << endl;
}

void test4()
{
	yyh::string s1("c");
	s1.insert(0, "a");
	cout << s1.c_str() << endl;
}

void test5()
{
	yyh::string s1("abcdefghijk");
	s1.erase(5, 20);
	cout << s1.c_str() << endl;
}

void test6()
{
	yyh::string s1;
	cin >> s1;
	cout << s1;
}

int main()
{
	//test1();
	//test2();
	//test4();
	//test5();
	test6();
	return 0;
}