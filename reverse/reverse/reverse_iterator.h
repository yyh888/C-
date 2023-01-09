#pragma once
#include <iostream>
using namespace std;

namespace yyh
{
	template<class Iterator, class Ref, class Ptr>
	class reverse_iterator
	{
	public:
		typedef reverse_iterator<Iterator, Ref, Ptr> iterator;

		reverse_iterator(Iterator it)
			: _it(it)
		{}

		Ref operator*()
		{
			Iterator tmp = _it;
			return *--tmp;
		}

		Ptr operator->()
		{
			return &(operetor*());
		}

		iterator& operator++()
		{
			--_it;
			return *this;
		}

		iterator& operator--()
		{
			++_it;
			return *this;
		}

		bool operator!=(const iterator& s) const
		{
			return _it != s._it;
		}

	private:
		Iterator _it;
	};
}