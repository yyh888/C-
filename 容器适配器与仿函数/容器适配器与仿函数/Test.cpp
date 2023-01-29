#include <iostream>
#include <vector>
#include <list>

using namespace std;

//namespace yyh
//{
//	template <class T, class container = vector<T>>
//	class stack
//	{
//	public:
//		void push(const T& x)
//		{
//			_con.push_back(x);
//		}
//
//		void pop()
//		{
//			_con.pop_back();
//		}
//
//		const T& top()
//		{
//			return _con.back();
//		}
//
//		bool empty()
//		{
//			return _con.empty();
//		}
//	private:
//		container _con;
//	};
//}
//
//int main()
//{
//	yyh::stack<int, vector<int>> st1;
//	yyh::stack<int, list<int>> st2;
//	return 0;
//}


namespace yyh
{
	template <class T>
	struct less
	{
		bool operator()(const T& x, const T& y)
		{
			return x < y;
		}
	};

	template <class T>
	struct greater
	{
		bool operator()(const T& x, const T& y)
		{
			return x > y;
		}
	};

	template <class T, class compare>
	void BubbleSort(vector<T>& a, compare com)
	{
		for (int i = 0; i < a.size() - 1; i++)
		{
			//用来判断是否交换过，提高效率
			int flag = 1;
			for (int cur = 0; cur < a.size() - 1 - i; cur++)
			{
				if (com(a[cur + 1], a[cur]))
				{
					swap(a[cur], a[cur + 1]);
					flag = 0;
				}
			}
			if (flag)
			{
				break;
			}
		}
	}
}

int main()
{
	yyh::less<int> lessFun;
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(5);
	v1.push_back(2);
	v1.push_back(4);
	v1.push_back(3);
	yyh::BubbleSort(v1, lessFun);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	return 0;
}