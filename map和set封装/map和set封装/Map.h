#pragma once
#include "RBTree.h"

namespace yyh
{
	template <class K, class V>
	class map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};

	public:
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT >::iterator iterator;
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT >::const_iterator \
			const_iterator;
		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		const_iterator begin() const
		{
			return _t.begin();
		}

		const_iterator end() const
		{
			return _t.end();
		}

		pair<iterator, bool> insert(const const pair<K, V>& kv)
		{
			return _t.insert(kv);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = insert(make_pair(key, V()));
			return ret.first->second;
		}

	private:
		RBTree<K, pair<const K, V>, MapKeyOfT> _t;
	};

	void test_map()
	{
		map<string, int> m;
		string arr[] = { "北京", "武汉", "广州", "上海", "北京", "北京", "广州",
	"上海", "上海" };
		for (auto& e : arr)
		{
			m[e]++;
		}
		map<string, int>::iterator it = m.begin();
		while (it != m.end())
		{
			cout << it->first << "=>" << it->second << endl;
			++it;
		}
		cout << endl;
	}
}
