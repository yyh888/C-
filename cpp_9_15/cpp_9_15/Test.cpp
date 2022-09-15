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
	yyh::string s1("aaaaaaaa");
	s1.yyh::string::append("cccccccccccccccc");
	cout << s1.c_str() << endl;
}

int main()
{
	//test1();
	test2();
	return 0;
}