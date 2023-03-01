#pragma once
#include "HashTable.h"

namespace yyh
{
	template <class K, class V, class Hash = HashKey<K>>
	class unordered_map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename hashbucket::HashTable<K, pair<K, V>, Hash, MapKeyOfT>::iterator iterator;
		typedef typename hashbucket::HashTable<K, pair<K, V>, Hash, MapKeyOfT>::const_iterator const_iterator;
		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		const_iterator cbegin()
		{
			return _ht.cbegin();
		}

		const_iterator cend()
		{
			return _ht.cend();
		}

		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _ht.insert(kv);
		}

		bool find(const K& key)
		{
			return _ht.find(key);
		}

		bool erase(const K& key)
		{
			return _ht.erase(key);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _ht.insert(make_pair(key, V()));
			return ret.first->second;
		}
	private:
		hashbucket::HashTable<K, pair<K, V>, Hash, MapKeyOfT> _ht;
	};
}