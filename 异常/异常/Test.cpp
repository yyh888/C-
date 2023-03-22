#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <windows.h>
using std::cin;
using std::cout;
using std::endl;

//double Div(double left, double right)
//{
//	if (right == 0)
//	{
//		throw "除0错误!";
//	}
//	else
//	{
//		return left / right;
//	}
//}
//
//void fun()
//{
//	int* p = new int[10];
//	try
//	{
//		double left, right;
//		cin >> left >> right;
//		cout << Div(left, right) << endl;
//	}
//	catch (const char* errstr)
//	{
//		cout << "--delete--" << endl;
//		delete[]p;
//		// 重新抛出
//		throw errstr;
//	}
//	catch (...) 
//	{
//		cout << "未知异常!" << endl;
//	}
//}
//
//int main()
//{
//	try
//	{
//		fun();
//	}
//	catch (const char* errstr)
//	{
//		cout << errstr << endl;
//	}
//	catch (...) 
//	{
//		cout << "未知异常!" << endl;
//	}
//	return 0;
//}


//class Exception
//{
//public:
//	Exception(const std::string& str, int id)
//		: _errstr(str)
//		, _id(id)
//	{}
//
//	// 获取异常信息
//	virtual std::string what() const
//	{
//		return _errstr;
//	}
//protected:
//	std::string _errstr;
//	int _id;
//};
//
//// A错误
//class AException : public Exception
//{
//public:
//	AException(const std::string& str, int id, const std::string& A)
//		: Exception(str, id)
//		, _A(A)// const成员变量只能走初始化列表
//	{}
//
//	virtual std::string what() const
//	{
//		std::string str("A Exception:");
//		str += _errstr;
//		str += "->";
//		str += _A;
//		return str;
//	}
//private:
//	const std::string _A;
//};
//
//// B异常
//class BException : public Exception
//{
//public:
//	BException(const std::string& str, int id)
//		: Exception(str, id)
//	{}
//
//	virtual std::string what() const
//	{
//		std::string str("B Exception:");
//		str += _errstr;
//		return str;
//	}
//private:
//};
//
//// C异常
//class CException : public Exception
//{
//public:
//	CException(const std::string& str, int id, const std::string& C)
//		: Exception(str, id)
//		, _C(C)// const成员变量只能走初始化列表
//	{}
//
//	virtual std::string what() const
//	{
//		std::string str("C Exception:");
//		str += _errstr;
//		str += "->";
//		str += _C;
//		return str;
//	}
//private:
//	const std::string _C;
//};
//
//
//void A()
//{
//	srand(time(0));
//	if (rand() % 7 == 0)
//	{
//		throw AException("权限不足", 100, "A出问题");
//	}
//	cout << "调用成功" << endl;
//}
//
//void B()
//{
//	srand(time(0));
//	if (rand() % 5 == 0)
//	{
//		throw BException("权限不足", 100);
//	}
//	else if (rand() % 6 == 0)
//	{
//		throw BException("数据不存在", 101);
//	}
//	A();
//}
//void C()
//{
//	srand(time(0));
//	if (rand() % 3 == 0)
//	{
//		throw CException("请求资源不存在", 100, "C出问题");
//	}
//	else if (rand() % 4 == 0)
//	{
//		throw CException("权限不足", 101, "C出问题");
//	}
//	B();
//}
//
//int main()
//{
//	while (1)
//	{
//		Sleep(500);
//		try {
//			C();
//		}
//		catch (const Exception& e) // 这里捕获父类对象就可以
//		{
//			// 多态
//			cout << e.what() << endl;
//		}
//		catch (...)
//		{
//			cout << "未知错误!" << endl;
//		}
//	}
//	return 0;
//}


// 这里表示这个函数会抛出A/B/C/D中的某种类型的异常
void fun() throw(A，B，C，D);
// 这里表示这个函数只会抛出bad_alloc的异常
void* operator new (std::size_t size) throw (std::bad_alloc);
// 这里表示这个函数不会抛出异常
void* operator delete (std::size_t size, void* ptr) throw();
// C++11 中新增的noexcept，表示不会抛异常
thread() noexcept;
thread(thread&& x) noexcept;