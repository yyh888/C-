#include <iostream>
using namespace std;

//int main()
//{
//	//c”Ô—‘
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p2 = (int*)malloc(sizeof(int) * 10);
//	free(p1);
//	free(p2);
//	p1 = p2 = NULL;
//	//c++
//	int* p3 = new int;
//	int* p4 = new int[10];
//	delete p3;
//	delete[] p4;
//	p3 = p4 = nullptr;
//	return 0;
//}


class A
{
public:
	A(int a = 0)
		: _a(a)
	{}

	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};

//int main()
//{
//	A* p1 = (A*)malloc(sizeof(A) * 10);
//	free(p1);
//	p1 = NULL;
//	A* p2 = new A;
//	delete p2;
//	p2 = nullptr;
//	A* p4 = new A[5]{ 1, 2, 3, 4, 5 };
//	return 0;
//}


//int main()
//{
//	//c”Ô—‘
//	int* p = (int*)malloc(sizeof(int) * INT_MAX);
//	if (p == NULL)
//	{
//		printf("%d\n", errno);
//		printf("malloc fail\n");
//		exit(-1);
//	}
//	else
//	{
//		printf("%p\n", p);
//	}
//	return 0;
//}


//int main()
//{
//	try
//	{
//		char* p1 = new char[INT_MAX];
//	}
//	catch(const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}

//class Stack
//{
//public:
//	Stack(int capacity = 10)
//		: _top(0)
//		, _capacity(capacity)
//	{
//		_a = new int[capacity];
//	}
//
//	~Stack()
//	{
//		delete[]_a;
//		_capacity = _top = 0;
//		_a = nullptr;
//	}
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//
//
//int main()
//{
//	Stack* s = new Stack;
//	delete s;
//	return 0;
//}


class Stack
{
public:
	Stack(int capacity = 10)
		: _top(0)
		, _capacity(capacity)
	{
		_a = new int[capacity];
	}

	~Stack()
	{
		delete[] _a;
		_capacity = 0;
		_top = 0;
		_a = nullptr;
	}
private:
	int* _a;
	int _top;
	int _capacity;
};

Stack* s = (Stack*)operator new(sizeof(Stack));

int main()
{
	return 0;
}