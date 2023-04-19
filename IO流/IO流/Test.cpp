#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

//int main()
//{
//	string str;
//	while (cin >> str)
//	{
//		cout << str << endl;
//	}
//	return 0;
//}

//class A
//{
//public:
//	A(int a)
//		: _a(a)
//	{}
//
//	operator int()
//	{
//		return _a;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	// 内置类型转换成自定义类型
//	A a = 1;
//	// 自定义类型转化成内置类型
//	int aa = a;
//	cout << aa << endl;
//	return 0;
//}


//struct ServerInfo
//{
//	char _address[32];
//	int _port;
//};
//
//
//struct Config
//{
//public:
//	Config(const char* filename)
//		: _filename(filename)
//	{}
//
//	void Write(ServerInfo info)
//	{
//		ofstream ofs(_filename, std::ios_base::out | std::ios_base::binary);
//		ofs.write((char*)&info, sizeof info);
//	}
//
//	void Read(ServerInfo& info)
//	{
//		ifstream ifs(_filename, std::ios_base::in | std::ios_base::binary);
//		ifs.read((char*)&info, sizeof info);
//	}
//private:
//	string _filename;
//};
//
//int main()
//{
//	Config con("text.txt");
//	//ServerInfo si = { "aaaaaa", 910 };
//	//con.Write(si);
//
//	ServerInfo si;
//	con.Read(si);
//	cout << si._address << " " << si._port << endl;
//	return 0;
//}

//struct ServerInfo
//{
//	char _address[32];
//	int _port;
//};
//
//
//struct Config
//{
//public:
//	Config(const char* filename)
//		: _filename(filename)
//	{}
//
//	void Write(ServerInfo info)
//	{
//		ofstream ofs(_filename);
//		// 重载
//		ofs << info._address << endl;
//		ofs << info._port << endl;
//	}
//
//	void Read(ServerInfo& info)
//	{
//		ifstream ifs(_filename);
//		// 重载
//		ifs >> info._address;
//		ifs >> info._port;
//	}
//private:
//	string _filename;
//};
//
//int main()
//{
//	Config con("text.txt");
//	/*ServerInfo si = { "aaaaaa", 910 };
//	con.Write(si);*/
//
//	ServerInfo si;
//	con.Read(si);
//	cout << si._address << " " << si._port << endl;
//	return 0;
//}

//int main()
//{
//	int a = 123;
//	const char* b = "456";
//	double c = 78.9;
//	ostringstream os;
//	os << a << " ";
//	os << b << " ";
//	os << c << " ";
//	string ret = os.str();
//	cout << ret << endl;
//	int d;
//	char e[20];
//	double f;
//	istringstream is(ret);
//	is >> d >> e >> f;
//	cout << d << " ";
//	cout << e << " ";
//	cout << e << " ";
//	return 0;
//}


class Date
{
	friend ostream& operator << (ostream& out, const Date& d);
	friend istream& operator >> (istream& in, Date& d);
public:
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
};
istream& operator >> (istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}
ostream& operator << (ostream& out, const Date& d)
{
	out << d._year << " " << d._month << " " << d._day;
	return out;
}


struct ServerInfo
{
	friend istream& operator >> (istream& in, ServerInfo& si);
	friend ostream& operator << (ostream& out, ServerInfo& si);
	string _name;// 昵称
	Date _d;// 时间
	string _msg;// 信息
};

istream& operator >> (istream& in, ServerInfo& si)
{
	in >> si._name  >> si._d >> si._msg;
	return in;
}

ostream& operator << (ostream& out, ServerInfo& si)
{
	out << si._name << " ";
	out << si._d << " ";
	out << si._msg << " ";
	return out;
}

int main()
{
	ServerInfo p{ "海阔天空", {2023, 4, 19}, "hello" };
	stringstream os;
	os << p;
	string ret = os.str();

	ServerInfo is;
	stringstream oss(ret);
	oss >> is;
	cout << "-------------------------------------------------------" << endl;
	cout << "昵称：" << is._name << " ";
	cout << is._d << endl;
	cout << is._name << ": " << is._msg << endl;
	cout << "-------------------------------------------------------" << endl;
	return 0;
}