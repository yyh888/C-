#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

//template <class T, size_t N = 10>
//class Arr
//{
//private:
//	T a[N];
//};

//class Stu
//{
//public:
//	Stu(const char* name, int age)
//		: _age(age)
//	{
//		strcpy(_name, name);
//	}
//
//	bool operator<(Stu& s)
//	{
//		return _age < s._age;
//	}
//private:
//	char _name[5];
//	int _age;
//};
//
//template <class T>
//bool Less(T a, T b)
//{
//	return a < b;
//}
//
//// Less 的特化
//template <>
//bool Less<Stu*>(Stu* a, Stu* b)
//{
//	return *a < *b;
//}
//
//int main()
//{
//	Stu s1("a", 10), s2("b", 20);
//	cout << Less(s1, s2) << endl;
//	cout << Less(&s1, &s2) << endl;
//	return 0;
//}


//template <class T1, class T2>
//class A
//{
//public:
//	A()
//	{
//		cout << "<T1 T2>" << endl;
//	}
//private:
//	T1 a;
//	T2 b;
//};
//
//template<>
//class A<double, double>
//{
//public:
//	A()
//	{
//		cout << "<double, double>" << endl;
//	}
//};
//
//int main()
//{
//	A<int, int> a;
//	A<double, double> b;
//	return 0;
//}

//template <class T1, class T2>
//class A
//{
//public:
//	A()
//	{
//		cout << "<T1 T2>" << endl;
//	}
//private:
//	T1 a;
//	T2 b;
//};
//
//// 半特化
//template<class T>
//class A<T, char>
//{
//public:
//	A()
//	{
//		cout << "<T, double>" << endl;
//	}
//};


// a.h
template<class T>
T Add(const T& left, const T& right);
// a.cpp
template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}