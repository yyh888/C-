#include <iostream>

using namespace std;

//class A
//{
//private:
//	A()
//	{}
//};
//
//int main()
//{
//	A aa;
//	return 0;
//}


//class A final
//{
//public:
//};
//
//class B : public A
//{
//public:
//};
//
//int main()
//{
//	B a;
//	a.print();
//	return 0;
//}

//class A
//{
//public:
//	virtual void print()
//	{
//		cout << "A" << endl;
//	}
//};
//
//class B : public A
//{
//public:
//	virtual void print()
//	{
//		cout << "B" << endl;
//	}
//};
//
//int main()
//{
//	A a;
//	B b;
//	A* ptr = &b;
//	ptr->print();
//	return 0;
//}
//

//class C
//{
//
//};
//
//class D : public C
//{
//
//};
//
//class A
//{
//public:
//	// 虚函数
//	virtual void Print()
//	{
//		cout << "A" << endl;
//	}
//};
//
//class B : public A
//{
//public:
//	// 检查是否被重写
//	virtual void Print() override
//	{
//		cout << "B" << endl;
//	}
//};
//
//int main()
//{
//	A a;
//	B b;
//	A* pa = &a;
//	A* pb = &b;
//	pa->Print();
//	pb->Print();
//	return 0;
//}


//class A
//{
//public:
//	virtual ~A()
//	{
//		cout << "~A() " << _a << endl;
//		delete []_a;
//	}
//
//	int* _a = new int[20];
//};
//
//class B : public A
//{
//public:
//	virtual ~B()
//	{
//		cout << "~B() " << _b << endl;
//		delete[]_b;
//	}
//
//	int* _b = new int[20];
//};
//
//int main()
//{
//	A* a = new A;
//	A* b = new B;
//	delete a;
//	delete b;
//	return 0;
//}


//class A
//{
//public:
//	// 纯虚函数
//	virtual void Print() = 0;
//};
//
//class B : public A
//{
//public:
//	virtual void Print()
//	{
//		cout << "B" << endl;
//	}
//};
//
//int main()
//{
//	A a; // yes
//	B b; // no
//	return 0;
//}


//class A
//{
//public:
//	virtual void Print1() 
//	{
//		cout << "A::Print1()" << endl;
//	}
//	virtual void Print2()
//	{
//		cout << "A::Print2()" << endl;
//	}
//	int _a = 0;
//};
//
//class B : public A
//{
//public:
//	virtual void Print1()
//	{
//		cout << "B::Print1()" << endl;
//	}
//	virtual void Print2()
//	{
//		cout << "B::Print2()" << endl;
//	}
//	int _b = 0;
//};
//
//class C : public A, public B
//{
//public:
//	virtual void Print1()
//	{
//		cout << "C::Print1()" << endl;
//	}
//	virtual void Print3()
//	{
//		cout << "C::Print3()" << endl;
//	}
//	int c = 0;
//};
//
//typedef void(*VfPtr)();
//
//void VfPrint(VfPtr vft[])// 打印虚表
//{
//	for (int i = 0; vft[i]; i++)
//	{
//		printf("[%d]:%p->", i, vft[i]);
//		vft[i]();
//	}
//	cout << endl;
//}
//
//int main()
//{
//	A a;
//	B b;
//	C c;
//	VfPrint((VfPtr*)(*(int*)&a));
//	VfPrint((VfPtr*)(*(int*)&b));
//	// 第一张虚表
//	VfPrint((VfPtr*)(*(int*)&c));
//	// 第二张虚表
//	VfPrint((VfPtr*)(*(int*)((char*)&c + sizeof(A))));
//	return 0;
//}


//class A
//{
//public:
//	virtual void fun() = 0;
//};
//
//class B : public A
//{
//public:
//	virtual void fun() {}
//};
//
//int main()
//{
//	B b;
//	return 0;
//}

