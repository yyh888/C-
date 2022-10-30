#pragma once

namespace yyh
{
	template<class Iterator, class Ref, class Ptr>
	class reverse_iterator
	{
	public:
		typedef reverse_iterator<Iterator, Ref, Ptr> iterator;

		reverse_iterator(Iterator p)
			: _p(p)
		{}

		iterator& operator++()
		{
			--_p;
			return *this;
		}

		iterator& operator--()
		{
			++_p;
			return *this;
		}

		Ref operator*()
		{
			Iterator it = _p;
			return *--it;
		}

		Ptr operator->()
		{
			return &operator*();
		}

		bool operator!=(const iterator& x)
		{
			return _p != x._p;
		}
	private:
		Iterator _p;
	};
}