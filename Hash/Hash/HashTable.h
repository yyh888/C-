#pragma once

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <class K>
struct HashKey
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

// 字符串哈希
template <>
struct HashKey<string>
{
	size_t operator()(const string& key)
	{
		size_t ans = 0;
		for (size_t i = 0; i < key.size(); i++)
		{
			ans *= 131;
			ans += i;
		}
		return ans;
	}
};

namespace hashclose
{
	// 状态
	enum Sta
	{
		EXIST,
		DELETE,
		EMPTY,
	};

	// 数据类型
	template <class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		Sta _state = EMPTY;
	};

	// 哈希表结构
	template <class K, class V, class GetKey = HashKey<K>>
	class HashTable
	{
		typedef HashData<K, V> data;
	public:
		HashTable()
			: _n(0)
		{
			_tables.resize(10);
		}

		bool insert(const pair<K, V>& kv)
		{
			// 重复
			if (find(kv.first)) return false;
			// 负载因子
			size_t load = _n * 10 / _tables.size();
			if (load >= 7)
			{
				// 出作用域后销毁
				HashTable<K, V> newhash;
				newhash._tables.resize(2 * _tables.size());
				for (auto& e : _tables)
				{
					if (e._state == EXIST)
					{
						newhash.insert(e._kv);
					}
				}
				_tables.swap(newhash._tables);
			}
			GetKey Get;
			size_t hashI = Get(kv.first) % _tables.size();
			while (_tables[hashI]._state == EXIST)
			{
				++hashI;
				hashI %= _tables.size();
			}
			_tables[hashI]._kv = kv;
			_tables[hashI]._state = EXIST;
			++_n;
			return true;
		}

		data* find(const K& key)
		{
			GetKey Get;
			size_t hashI = Get(key) % _tables.size();
			size_t startI = hashI;// 最多循环一圈
			while (_tables[hashI]._state != EMPTY)
			{
				if (_tables[hashI]._state == EXIST
					&& _tables[hashI]._kv.first == key)
				{
					return &_tables[hashI];
				}
				++hashI;
				hashI %= _tables.size();
				if (hashI == startI) break;
			}
			return nullptr;
		}

		bool erase(const K& key)
		{
			data* node = find(key);
			if (node)
			{
				node->_state = DELETE;
				return true;
			}
			return false;
		}
	private:
		vector<data> _tables;
		size_t _n;// 有效数据个数
	};
}

namespace hashbucket
{
	template <class T>
	struct HashNode
	{
		HashNode(const T& data)
			: _data(data)
			, _next(nullptr)
		{}

		T _data;
		HashNode<T>* _next;
	};

	// 前置声明
	template <class K, class T, class Hash, class KeyOfT>
	class HashTable;

	template <class K, class T, class Hash, class KeyOfT>
	struct HashIterator
	{
		typedef HashNode<T> Node;
		typedef HashIterator<K, T, Hash, KeyOfT> self;
		typedef HashTable<K, T, Hash, KeyOfT> HT;

		HashIterator(HT* ht, Node* node)// 传递指针
			: _node(node)
			, _ht(ht)
		{}

		T& operator*()
		{
			return _node->_data;
		}

		T* operator->()
		{
			return &_node->_data;
		}

		bool operator!=(const self& it) const
		{
			return _node != it._node;
		}

		self& operator++()
		{
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				// 找下一个桶
				KeyOfT kot;
				Hash hash;
				size_t idx = hash(kot(_node->_data)) % _ht->_tables.size();
				idx++;
				while (idx < _ht->_tables.size())
				{
					if (_ht->_tables[idx] != nullptr)
					{
						_node = _ht->_tables[idx];
						break;
					}
					else
					{
						idx++;
					}
				}

				if (idx == _ht->_tables.size())
				{
					_node = nullptr;
				}
			}
			return *this;
		}

		HT* _ht;
		Node* _node;
	};

	template <class K, class T, class Hash, class KeyOfT>
	struct ConstHashIterator
	{
		typedef HashNode<T> Node;
		typedef ConstHashIterator<K, T, Hash, KeyOfT> self;
		typedef HashTable<K, T, Hash, KeyOfT> HT;

		ConstHashIterator(const HT* ht, const Node* node)// 传递指针
			: _node(node)
			, _ht(ht)
		{}

		const T& operator*() const
		{
			return _node->_data;
		}

		const T* operator->() const
		{
			return &_node->_data;
		}

		bool operator!=(const self& it) const
		{
			return _node != it._node;
		}

		self& operator++()
		{
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				// 找下一个桶
				KeyOfT kot;
				Hash hash;
				size_t idx = hash(kot(_node->_data)) % _ht->_tables.size();
				idx++;
				while (idx < _ht->_tables.size())
				{
					if (_ht->_tables[idx] != nullptr)
					{
						_node = _ht->_tables[idx];
						break;
					}
					else
					{
						idx++;
					}
				}

				if (idx == _ht->_tables.size())
				{
					_node = nullptr;
				}
			}
			return *this;
		}
		const HT* _ht;
		const Node* _node;
	};

	template <class K, class T, class GetKey, class KeyOfT>
	class HashTable
	{
		typedef HashNode<T> Node;

		template<class K, class T, class GetKey, class KeyOfT>
		friend struct HashIterator;// 迭代器需要访问私有

		template <class K, class T, class Hash, class KeyOfT>
		friend struct ConstHashIterator;

	public:
		typedef HashIterator<K, T, GetKey, KeyOfT> iterator;
		typedef ConstHashIterator<K, T, GetKey, KeyOfT> const_iterator;
		iterator begin()
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				if (_tables[i])
				{
					return iterator(this, _tables[i]);
				}
			}
			return iterator(this, nullptr);
		}

		iterator end()
		{
			return iterator(this, nullptr);
		}

		const_iterator cbegin()
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				if (_tables[i])
				{
					return const_iterator(this, _tables[i]);
				}
			}
			return const_iterator(this, nullptr);
		}

		const_iterator cend()
		{
			return const_iterator(this, nullptr);
		}

		HashTable()
			: _n(0)
		{
			_tables.resize(10);
		}

		~HashTable()
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_tables[i] = nullptr;
			}
		}

		pair<iterator, bool> insert(const T& data)
		{
			// 重复
			iterator it = find(KeyOfT()(data));
			if (it != end())
			{
				return make_pair(it, false);
			}
			// 负载因子为1扩容
			if (_tables.size() == _n)
			{
				vector<Node*> newtable;
				newtable.resize(2 * _n);
				for (size_t i = 0; i < _tables.size(); i++)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;
						size_t idx = GetKey()(KeyOfT()(data)) % newtable.size();
						cur->_next = newtable[idx];
						newtable[idx] = cur;
						cur = next;
					}
					_tables[i] = nullptr;
				}
				_tables.swap(newtable);
			}

			size_t hashI = GetKey()(KeyOfT()(data)) % _tables.size();
			Node* newnode = new Node(data);
			newnode->_next = _tables[hashI];
			_tables[hashI] = newnode;
			++_n;
			return make_pair(iterator(this, newnode), true);
		}

		iterator find(const K& key)
		{
			size_t idx = GetKey()(key) % _tables.size();
			Node* cur = _tables[idx];
			while (cur)
			{
				if (KeyOfT()(cur->_data) == key)
					return iterator(this, cur);
				else
					cur = cur->_next;
			}
			return end();
		}

		bool erase(const K& key)
		{
			size_t idx = GetKey()(KeyOfT()(key)) % _tables.size();
			Node* cur = _tables[idx];
			Node* pre = nullptr;
			while (cur)
			{
				if (cur->_data == key)
				{
					if (pre = nullptr)
					{
						_tables[idx] = nullptr;
					}
					else
					{
						pre->_next = cur->_next;
					}
					delete cur;
					--_n;
					return true;
				}
				else
				{
					pre = cur;
					cur = cur->_next;
				}
			}
			return false;
		}
	private:
		vector<Node*> _tables;
		size_t _n = 0;
	};
}
