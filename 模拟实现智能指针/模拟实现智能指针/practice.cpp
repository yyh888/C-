#include <iostream>
using namespace std;


namespace yyh
{
	template <class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr)
			: _ptr(ptr)
		{}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		T& operator[](size_t pos)
		{
			return _ptr[pos];
		}

		~auto_ptr()
		{
			delete _ptr;
			//std::cout << "delete[]_ptr" << std::endl;
		}
	private:
		T* _ptr;
	};

	template <class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr)
			: _ptr(ptr)
		{}

		unique_ptr(const unique_ptr<T>& p) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>& p) = delete;

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		T& operator[](size_t pos)
		{
			return _ptr[pos];
		}

		~unique_ptr()
		{
			delete _ptr;
			//std::cout << "delete[]_ptr" << std::endl;
		}
	private:
		T* _ptr;
	};

	template <class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr)
			: _ptr(ptr)
		{
			_pcnt = new int(1);
		}

		shared_ptr(const unique_ptr<T>& p)
		{
			_ptr = p._ptr;
			_pcnt = p.pcnt;
			++(*_pcnt);
		}

		shared_ptr<T>& operator=(const shared_ptr<T> p)
		{
			if (_ptr != p._ptr)
			{
				--(*_pcnt);
				if (*_pcnt == 0)
				{
					delete _ptr;
					delete _pcnt;
				}
				_ptr = p._ptr;
				_pcnt = p._pcnt;
				++(*_pcnt);
			}
			return *this;
		}

		~shared_ptr()
		{
			(*_pcnt)--;
			if (*_pcnt == 0)
			{
				cout << _ptr << endl;
				delete _ptr;
				delete _pcnt;
			}
		}
	private:
		T* _ptr;
		int* _pcnt;
	};
}


int main()
{
	yyh::shared_ptr<int> p1 = new int[10];
	yyh::shared_ptr<int> p2(p1);
	yyh::shared_ptr<int> p3 = new int(1);
	p2 = p3;
	return 0;
}