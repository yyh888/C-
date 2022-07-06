#include<iostream>

using namespace std;


//class B
//{
//public:
//	B()
//		: _x(0)
//	{
//		cout << "B()" << endl;
//	}
//private:
//	int _x;
//};
//
//class A
//{
//public:
//private:
//	int _a = 0;
//	int* _p = nullptr;
//	B _b;
//};
//
//
//int main()
//{
//	A aa;
//	return 0;
//}




//class A
//{
//public:
//	class B
//	{
//	public:
//		void fun(const A& a)
//		{
//			cout << a._a << endl;
//			cout << a._p << endl;
//		}
//	};
//private:
//	int _a = 0;
//	int* _p = nullptr;
//};
//
//
//int main()
//{
//	A aa;
//	A::B b;
//	b.fun(aa);
//	return 0;
//}




//int main()
//{
//	int a = 0;
//	int b = 1;
//	cout << "a: " << &a << endl;
//	cout << "b: " << &b << endl;
//	return 0;
//}


//int main()
//{
//	int* p1 = (int*)malloc(sizeof(int) * 4);
//	int* p2 = (int*)malloc(sizeof(int) * 4);
//	cout << "p1: " << p1 << endl;
//	cout << "p2: " << p2 << endl;
//	return 0;
//}



//int main()
//{
//	int* p1 = (int*)malloc(sizeof(int) * 10);
//	int* p2 = new int[10];
//	free(p1);
//	delete[] p2;
//	int* p3 = (int*)malloc(sizeof(int));
//	int* p4 = new int;
//	free(p3);
//	delete p4;
//	return 0;
//}



struct ListNode
{
	ListNode* _next;
	ListNode* _prev;
	int _val;
	ListNode(int val = 0)
		: _next(nullptr)
		, _prev(nullptr)
		, _val(val)
	{}
};


int main()
{
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	ListNode* n2 = new ListNode;
	return 0;
}