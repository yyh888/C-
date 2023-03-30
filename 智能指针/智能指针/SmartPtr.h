#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <memory>

using std::cin;
using std::cout;
using std::endl;

template <class T>
class DefultDelete// 默认
{
public:
	void operator()(T* ptr)
	{
		delete ptr;
	}
};

template <class D>
class Delete
{
public:
	void operator()(const D* del)
	{
		delete[]del;
		cout << "delete[]del" << endl;
	}
};

template <class T, class D = DefultDelete<T>>
class SmartPtr
{
public:
	SmartPtr(T* ptr = nullptr)
		: _ptr(ptr)
		, _pcnt(new int(1))
		, _pmutex(new std::mutex)
	{}

	SmartPtr(const SmartPtr<T>& sp)
		: _ptr(sp._ptr)
		, _pcnt(sp._pcnt)
		, _pmutex(sp._pmutex)
	{
		_pmutex->lock();
		(*_pcnt)++;
		_pmutex->unlock();
	}

	~SmartPtr()
	{
		_pmutex->lock();
		(*_pcnt)--;
		_pmutex->unlock();
		if (*_pcnt == 0)
		{
			//delete _ptr;
			_del(_ptr);
			delete _pcnt;
			delete _pmutex;
			//cout << _ptr << endl;
		}
	}

	SmartPtr<T>& operator=(const SmartPtr<T>& sp)
	{
		if (_ptr != sp._ptr)
		{
			_pmutex->lock();
			(*_pcnt)--;
			_pmutex->unlock();
			if (*_pcnt == 0)
			{
				this->~SmartPtr();
				//delete _pcnt;
				//delete _ptr;
			}
			_ptr = sp._ptr;
			_pcnt = sp._pcnt;
			_pmutex = sp._pmutex;
			_pmutex->lock();
			(*_pcnt)++;
			_pmutex->unlock();
		}
		return *this;
	}

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

	// 获取引用计数值
	int use_count()
	{
		return *_pcnt;
	}

	T* get() const
	{
		return _ptr;
	}
private:
	T* _ptr;
	int* _pcnt;
	std::mutex* _pmutex;
	D _del;
};

namespace yyh
{
	template <class T>
	class weak_ptr
	{
	public:
		weak_ptr()
			: _ptr(nullptr)
		{}

		weak_ptr(const SmartPtr<T>& p)
			: _ptr(p.get())
		{}

		weak_ptr<T>& operator=(const SmartPtr<T>& p)
		{
			_ptr = p.get();
			return *this;
		}
	private:
		T* _ptr;
	};
}

struct ListNode
{
	int val;
	yyh::weak_ptr<ListNode> left;
	yyh::weak_ptr<ListNode> right;

	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}
};


void test()
{
	SmartPtr<ListNode> n1(new ListNode);
	SmartPtr<ListNode, Delete<ListNode>> n2(new ListNode[5]);
}

//void test()
//{
//	const int N = 100000;
//	SmartPtr<int> sp1(new int[10]);
//
//	std::thread t1([&]() {
//		for (int i = 0; i < N; i++)
//		{
//			SmartPtr<int> sp2 = sp1;
//		}
//		});
//	std::thread t2([&]() {
//		for (int i = 0; i < N; i++)
//		{
//			SmartPtr<int> sp3 = sp1;
//		}
//		});
//	t1.join();
//	t2.join();
//	cout << sp1.use_count() << endl;
//}