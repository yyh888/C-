#pragma once
#include "RBTree.h"


namespace yyh
{
	template <class K>
	class set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& k)
			{
				return k;
			}
		};
	public:
		typedef typename RBTree<K, K, SetKeyOfT >::const_iterator iterator;
		typedef typename RBTree<K, K, SetKeyOfT >::const_iterator const_iterator;
		iterator begin() const
		{
			return _t.begin();
		}

		iterator end() const
		{
			return _t.end();
		}

		pair<iterator, bool> insert(const K& k)
		{
			return _t.insert(k);
		}
	private:
		RBTree<K, K, SetKeyOfT> _t;
	};

	void test_set()
	{
		set<int> s;
		int a[] = { 1, 2, 7, 4, 6, 2, 1 };
		for (int& e : a)
		{
			s.insert(e);
		}
		set<int>::iterator it = s.begin();
		cout << endl;
	}
}