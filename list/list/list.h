#include <iostream>
#include <assert.h>
using namespace std;

namespace yyh
{
	template <class T>
	struct ListNode
	{
		ListNode(const T& val = T())
			: _next(nullptr)
			, _prev(nullptr)
			, _val(val)
		{}

		ListNode<T>* _next;
		ListNode<T>* _prev;
		T _val;
	};

	template <class T, class Ref, class Ptr>
	struct __list_iterator
	{
		typedef ListNode<T> Node;
		typedef __list_iterator<T, Ref, Ptr> iterator;
		Node* _p;

		__list_iterator(Node* p)
			: _p(p)
		{}

		iterator& operator--()
		{
			_p = _p->_prev;
			return *this;
		}

		iterator operator--(int)
		{
			iterator tmp(*this);
			_p = _p->_prev;
			return tmp;
		}

		iterator& operator++()
		{
			_p = _p->_next;
			return *this;
		}

		iterator operator++(int)
		{
			iterator tmp(*this);
			_p = _p->_next;
			return tmp;
		}

		Ref operator*()
		{
			return _p->_val;
		}

		bool operator!=(const iterator& x)
		{
			return _p != x._p;
		}

		Ptr operator->()
		{
			return &_p->_val;
		}
	};

	//template <class T>
	//struct _const__list_iterator
	//{
	//	typedef ListNode<T> Node;
	//	typedef _const__list_iterator const_iterator;
	//	Node* _p;

	//	_const__list_iterator(Node* p)
	//		: _p(p)
	//	{}

	//	const_iterator& operator--()
	//	{
	//		_p = _p->_prev;
	//		return *this;
	//	}

	//	const_iterator operator--(int)
	//	{
	//		const_iterator tmp(*this);
	//		_p = _p->_prev;
	//		return tmp;
	//	}

	//	const_iterator& operator++()
	//	{
	//		_p = _p->_next;
	//		return *this;
	//	}

	//	const_iterator operator++(int)
	//	{
	//		const_iterator tmp(*this);
	//		_p = _p->_next;
	//		return tmp;
	//	}

	//	const T& operator*()
	//	{
	//		return _p->_val;
	//	}

	//	bool operator!=(const const_iterator& x)
	//	{
	//		return _p != x._p;
	//	}
	//};

	template <class T>
	class list
	{
		typedef ListNode<T> Node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;
		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		template<class InputIterator>
		list(InputIterator first, InputIterator end)
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			while (first != end)
			{
				push_back(*first);
				first++;
			}
		}

		list(size_t n, const T& val = T())
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		/*list(int n, const T& val = T())
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			for (int i = 0; i < n; i++)
			{
				push_back(val);
			}
		}*/

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		/*list(const list<T>& lt)
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			for (auto& e : lt)
			{
				push_back(e);
			}
		}*/

		list(const list<T>& lt)
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			list<T> tmp(lt.begin(), lt.end());
			swap(_head, tmp._head);
		}

		/*list<T>& operator=(const list<T>& lt)
		{
			if (this != &lt)
			{
				clear();
				for (auto& e : lt)
				{
					push_back(e);
				}
			}
			return *this;
		}*/

		list<T>& operator=(list<T> lt)
		{
			swap(_head, lt._head);
			return *this;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				erase(it++);
			}
		}
		
		void push_front(const T& val)
		{
			insert(begin(), val);
		}

		void push_back(const T& val)
		{
			/*Node* newnode = new Node(val);
			Node* tail = _head->_prev;
			tail->_next = newnode;
			newnode->_prev = tail;
			_head->_prev = newnode;
			newnode->_next = _head;*/
			insert(end(), val);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}

		// posºó²åÈë
		iterator insert(iterator pos, const T& val)
		{
			Node* newnode = new Node(val);
			Node* cur = pos._p;
			Node* prev = cur->_prev;
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			return iterator(newnode);
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());
			Node* cur = pos._p;
			Node* next = cur->_next;
			cur->_next->_prev = cur->_prev;
			cur->_prev->_next = cur->_next;
			delete cur;
			return iterator(next);
		}

	private:
		Node* _head;
	};

	struct Date
	{
		int _year;
		int _month;
		int _day;

		Date(int year = 1, int month = 1, int day = 1)
			: _year(year)
			, _month(month)
			, _day(day)
		{}
	};

	void print(const list<int>& lt)
	{
		list<int>::const_iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}

	void fun1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;
		print(lt);
	}

	void fun2()
	{
		list<Date> lt;
		lt.push_back(Date(1, 1, 1));
		lt.push_back(Date(1, 1, 2));
		lt.push_back(Date(1, 1, 3));
		lt.push_back(Date(1, 1, 4));
		lt.pop_back();
		list<Date>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << it->_year << " / " << it->_month << " / " << it->_day << endl;
			it++;
		}
		list<Date> lt2(lt);
		list<Date>::iterator it2 = lt2.begin();
		while (it2 != lt2.end())
		{
			cout << it2->_year << " / " << it2->_month << " / " << it2->_day << endl;
			it2++;
		}
		lt.clear();
	}

	void fun3()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		list<int> lt2;
		lt2 = lt;
		for (auto& e : lt2)
		{
			cout << e << " ";
		}
	}

	void fun4()
	{
		list<double> lt(5, 3.3);
		for (auto& e : lt)
		{
			cout << e << " ";
		}
	}
}