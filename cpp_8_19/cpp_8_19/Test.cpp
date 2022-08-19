#include <iostream>
#include <string>
using namespace std;


//int main()
//{
//	string s1;
//	cout << s1.capacity() << endl;
//	cout << s1 << endl;
//	return 0;
//}


//int main()
//{
//	string s1;
//	cout << "size: " << s1.size() << endl;
//	cout << "capacity: " << s1.capacity() << endl;
//	cout << s1 << endl;
//	s1.resize(16, 'x');
//	cout << "size: " << s1.size() << endl;
//	cout << "capacity " << s1.capacity() << endl;
//	cout << s1 << endl;
//	return 0;
//}

//int main()
//{
//	string filename = "Test.cpp.txt";
//	size_t pos = filename.rfind('.');
//	if (pos != filename.npos)
//	{
//		//string suff(filename, pos);
//		string suff = filename.substr(pos);
//		cout << suff;
//	}
//	return 0;
//}

string GetDomain(const string& url1)
{
	size_t pos = url1.find(':');
	if (pos != url1.npos)
	{
		size_t start = pos + 3;
		size_t end = url1.find('/', start);
		string suf = url1.substr(start, end - start);
		return suf;
	}
	else
	{
		return string();
	}
}

string GetProtocol(const string& url1)
{
	size_t pos = url1.find(':');
	if (pos != url1.npos)
	{
		string suf = url1.substr(0, pos);
		return suf;
	}
	else
	{
		return string();
	}
}

int main()
{
	string url1 = "https://cplusplus.com/reference/string/string/";
	cout << GetDomain(url1) << endl;
	cout << GetProtocol(url1) << endl;
	return 0;
}