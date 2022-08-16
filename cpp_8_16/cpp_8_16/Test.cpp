#include <iostream>
using namespace std;

//int mian()
//{
//	int* p1 = (int*)malloc(sizeof(int) * 10);
//	int* p2 = new int[10];
//	free(p1);
//	delete[]p2;
//	int* p3 = (int*)malloc(sizeof(int));
//	int* p4 = new int;
//	free(p3);
//	delete p4;
//	return 0;
//}


struct ListNode
{
	int _val;
	ListNode* _next;
	ListNode* _prev;
	ListNode(int val = 0)
		: _val(val)
		, _next(NULL)
		, _prev(NULL)
	{
		cout << "ListNode()" << endl;
	}
};


int main()
{
	ListNode* p = (ListNode*)operator new(sizeof(ListNode));
	new(p)ListNode;
	p->~ListNode();//析构函数能显示调用
	operator delete(p);
	return 0;
}


//int main()
//{
//	ListNode* n1 = (ListNode*)malloc(sizeof(ListNode));
//	ListNode* n2 = new ListNode[4]{1, 2, 3, 4};
//	return 0;
//}