#include<iostream>

using namespace std;

//int main()
//{
//	char str[] = "A\x11T\101C";
//	int sz = sizeof(str);
//	//int sz1 = strlen(str);
//	cout << sz << endl;
//	return 0;
//}



//int main()
//{
//	int a = 10;
//	int* p = &a;
//	int*& rp = p;
//	int b = 20;
//	rp = &b;
//	cout << *rp << endl;
//	return 0;
//}



//int main()
//{
//	int* p = NULL;
//	int*& rp = p;
//	cout << rp << endl;
//}


//int fun(int f[], int m)
//{
//	int i, n;
//	for(i = 1, n = 0; i < m; i++)
//		if (f[i] % 2 == 0)
//		{
//			printf("f%d = %d\n", i, f[i]);
//			n = n + 1;
//		}
//	return n;
//}
//
//
//int main()
//{
//	int i, n = 0, f[10] = { 0, 1 };
//	for (i = 2; i < 10; i++)
//		f[i] = f[i - 1] + f[i - 2];
//		printf("n = %d\n", fun(f, 10));
//	return 0;
//}

//#define ADD(a, b) ((a) + (b))
//
//
//int main()
//{
//	int c = ADD(1, 2);
//	cout << c << endl;
//	printf("%d\n", 1 | 2 + 1 | 2);
//	return 0;
//}



int Add(int x, int y)
{
	return x + y;
}

int main()
{
	int c = Add(1, 2);
	cout << c << endl;
	return 0;
}