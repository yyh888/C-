#pragma once
#include "HashTable.h"

namespace yyh
{
	template <class K, class Hash = HashKey<K>>
	class unordered_set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename hashbucket::HashTable<K, K, Hash, SetKeyOfT>::iterator iterator;
		typedef typename hashbucket::HashTable<K, K, Hash, SetKeyOfT>::const_iterator const_iterator;
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

		pair<iterator, bool> insert(const K& key)
		{
			return _ht.insert(key);
		}

		bool find(const K& key)
		{
			return _ht.find(key);
		}

		bool erase(const K& key)
		{
			return _ht.erase(key);
		}

	private:
		hashbucket::HashTable<K, K, Hash, SetKeyOfT> _ht;
	};
}