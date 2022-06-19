#include<iostream>



using namespace std;


//inline int Add(int x, int y)
//{
//	return x + y;
//}
//
//
//int main()
//{
//	int c = Add(1, 2);
//	cout << c << endl;
//	return 0;
//}



//int main()
//{
//	int a = 0;
//	auto b = a;
//	auto a = 10;
//	return 0;
//}


//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		cout << a[i] << " ";
//	}
//	cout << endl;
//
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		a[i] *= 2;
//	}
//
//	for (auto& e : a)
//	{
//		e *= 2;
//	}
//
//	for (auto e : a)
//	{
//		cout << e << " ";
//	}
//	return 0;
//}



//void fun(int)
//{
//	cout << "(int)" << endl;
//}
//
//void fun(int*)
//{
//	cout << "(int*)" << endl;
//}
//
//
//
//int main()
//{
//	fun(0);
//	fun(nullptr);
//	return 0;
//}

//typedef int DataType;
//class Stack
//{
//public:
//	//ÉùÃ÷
//	void Init(int InitType = 4);
//	void Push(DataType x);
//private:
//	DataType* a;
//	int size;
//	int capacity;
//};
//
//
//void Stack::Init(int InitType)
//{
//	a = (DataType*)malloc(sizeof(int) * InitType);
//	size = 0;
//	capacity = InitType;
//}
//
//
//void Stack::Push(DataType x)
//{
//	a[size] = x;
//	size++;
//}
//
//
//int main()
//{
//	Stack st;
//	st.Init();
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//	st.Push(4);
//	Stack s1;
//	cout << sizeof(s1) << endl;
//	return 0;
//}




class a1
{
public:
	void ADD()
	{

	}
};

class a2
{

};


int main()
{
	a1 a1;
	a2 a2;
	cout << &a1 << endl;
	cout << &a2 << endl;
	return 0;
}