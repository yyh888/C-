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
//		throw "��0����!";
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
//		// �����׳�
//		throw errstr;
//	}
//	catch (...) 
//	{
//		cout << "δ֪�쳣!" << endl;
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
//		cout << "δ֪�쳣!" << endl;
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
//	// ��ȡ�쳣��Ϣ
//	virtual std::string what() const
//	{
//		return _errstr;
//	}
//protected:
//	std::string _errstr;
//	int _id;
//};
//
//// A����
//class AException : public Exception
//{
//public:
//	AException(const std::string& str, int id, const std::string& A)
//		: Exception(str, id)
//		, _A(A)// const��Ա����ֻ���߳�ʼ���б�
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
//// B�쳣
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
//// C�쳣
//class CException : public Exception
//{
//public:
//	CException(const std::string& str, int id, const std::string& C)
//		: Exception(str, id)
//		, _C(C)// const��Ա����ֻ���߳�ʼ���б�
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
//		throw AException("Ȩ�޲���", 100, "A������");
//	}
//	cout << "���óɹ�" << endl;
//}
//
//void B()
//{
//	srand(time(0));
//	if (rand() % 5 == 0)
//	{
//		throw BException("Ȩ�޲���", 100);
//	}
//	else if (rand() % 6 == 0)
//	{
//		throw BException("���ݲ�����", 101);
//	}
//	A();
//}
//void C()
//{
//	srand(time(0));
//	if (rand() % 3 == 0)
//	{
//		throw CException("������Դ������", 100, "C������");
//	}
//	else if (rand() % 4 == 0)
//	{
//		throw CException("Ȩ�޲���", 101, "C������");
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
//		catch (const Exception& e) // ���ﲶ�������Ϳ���
//		{
//			// ��̬
//			cout << e.what() << endl;
//		}
//		catch (...)
//		{
//			cout << "δ֪����!" << endl;
//		}
//	}
//	return 0;
//}


// �����ʾ����������׳�A/B/C/D�е�ĳ�����͵��쳣
void fun() throw(A��B��C��D);
// �����ʾ�������ֻ���׳�bad_alloc���쳣
void* operator new (std::size_t size) throw (std::bad_alloc);
// �����ʾ������������׳��쳣
void* operator delete (std::size_t size, void* ptr) throw();
// C++11 ��������noexcept����ʾ�������쳣
thread() noexcept;
thread(thread&& x) noexcept;