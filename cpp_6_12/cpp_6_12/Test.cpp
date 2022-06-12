#include<iostream>

using namespace std;


void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}



struct Stack
{
	int* a;
	int size;
	int capacity;
};


void StackInit(struct Stack& s, int k = 4)
{
	s.a = (int*)malloc(sizeof(int) * k);
	s.size = 0;
	s.capacity = k;
}



int main()
{
	/*int a = 10;
	int b = 20;
	Swap(a, b);
	cout << a << b << endl;*/
	struct Stack st;
	StackInit(st);
	return 0;
}