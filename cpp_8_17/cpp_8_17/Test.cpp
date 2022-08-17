#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

//template<class T1, class T2>
//T1 Add(const T1& a, const T2& b)
//{
//	return a + b;
//}
//
//
//int main()
//{
//	int a = 1, b = 2;
//	double c = 1.1, d = 2.2;
//	cout << Add(a, d) << endl;
//	return 0;
//}



//template<class T1, class T2>
//void Swap(T1& e1, T2& e2)
//{
//	T2 tmp = e1;
//	e1 = e2;
//	e2 = tmp;
//}
//
//int main()
//{
//	double a = 1.5, b = 2.1;
//	int c = 3, d = 4;
//	Swap<int>(c, b);
//	cout << a << " " <<  b << endl;
//	return 0;
//}

namespace yyh
{
	template<class T>
	class vector
	{
	public:
		vector()
			: _a(nullptr)
			, _size(0)
			, _capacity(0)
		{}
		~vector()
		{
			delete[]_a;
			_a = nullptr;
			_size = _capacity = 0;
		}
		void Push(T x)
		{
			if (_size == _capacity)
			{
				int newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				T* tmp = new T[newcapacity];
				if (_a)
				{
					memcpy(tmp, _a, sizeof(T) * _size);
					delete[]_a;
				}
				_a = tmp;
				_capacity = newcapacity;
			}
			_a[_size] = x;
			_size++;
		}
		T& operator[](size_t pos);
		size_t size();
	private:
		T* _a;
		size_t _size;
		size_t _capacity;
	};
	template<class T>
	T& vector<T>::operator[](size_t pos)
	{
		assert(pos < _size);
		return _a[pos];
	}
	template<class T>
	size_t vector<T>::size()
	{
		return _size;
	}
}


int main()
{
	yyh::vector<int>v1;
	v1.Push(1);
	v1.Push(2);
	v1.Push(3);
	v1.Push(4);
	v1.Push(5);
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
	return 0;
}