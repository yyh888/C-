#pragma once
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string>

using namespace std;

enum Colour
{
	RED,
	BLACK,
};

template <class T>
struct RBTreeNode
{
	RBTreeNode(const T& data)
		: _data(data)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _col(RED)
	{}

	T _data;
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	Colour _col;
};

template <class T, class Ref, class Ptr>
struct RBTIterator
{
	typedef RBTreeNode<T> Node;
	typedef RBTIterator<T, Ref, Ptr> self;
	typedef RBTIterator<T, T&, T*> iterator;

	RBTIterator(const iterator& s)
		: _node(s._node)
	{}

	RBTIterator(Node* node)
		: _node(node)
	{}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}

	bool operator!=(const self& it)
	{
		return _node != it._node;
	}

	bool operator==(const self& it)
	{
		return _node == it._node;
	}

	self& operator++()
	{
		if (_node->_right)
		{
			Node* min = _node->_right;
			while (min->_left)
			{
				min = min->_left;
			}
			_node = min;
		}
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && parent->_right == cur)
			{
				cur = parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		return *this;
	}

	self& operator--()
	{
		if (_node->_left)
		{
			Node* max = _node->_left;
			while (max && max->_right)
			{
				max = max->_right;
			}
			_node = max;
		}
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && parent->_left == cur)
			{
				cur = parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		return *this;
	}

	Node* _node;
};

template <class K, class T, class KeyOfT>
class RBTree
{
public:
	typedef RBTreeNode<T> Node;
	typedef RBTIterator<T, T&, T*> iterator;
	typedef RBTIterator<T, const T&, const T*> const_iterator;
	iterator begin()
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}
		return iterator(cur);
	}

	iterator end()
	{
		return iterator(nullptr);
	}

	const_iterator begin() const
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}
		return const_iterator(cur);
	}

	const_iterator end() const
	{
		return const_iterator(nullptr);
	}

	pair<iterator, bool> insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return make_pair(iterator(_root), true);
		}
		KeyOfT kot;// 仿函数比较
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (kot(cur->_data) > kot(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (kot(cur->_data) < kot(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else return make_pair(iterator(cur), false);
		}
		cur = new Node(data);
		Node* newnode = cur;
		if (kot(data) < kot(parent->_data))
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		cur->_parent = parent;

		while (parent && parent->_col == RED)
		{
			// 找g 与 u
			Node* g = parent->_parent;
			if (parent == g->_left)
			{
				Node* u = g->_right;
				// 情况一 u存在且为红
				if (u && u->_col == RED)
				{
					parent->_col = u->_col = BLACK;
					g->_col = RED;
					// 继续往上处理
					cur = g;
					parent = cur->_parent;
				}
				else // 情况二或情况三
				{
					if (cur == parent->_left)// 情况二
					{
						//   g
						//  p
						// c
						RotateR(g);
						parent->_col = BLACK;
						g->_col = RED;
					}
					else// 情况三
					{
						//  g
						// p
						//  c
						RotateL(parent);
						RotateR(g);
						//   c
						// p   g
						cur->_col = BLACK;
						g->_col = RED;
					}
					break;
				}
			}
			else
			{
				Node* u = g->_left;
				// 情况一
				if (u && u->_col == RED)
				{
					u->_col = parent->_col = BLACK;
					g->_col = RED;
					cur = g;
					parent = cur->_parent;
				}
				else
				{
					// 情况二
					// g
					//  p
					//   c
					if (cur == parent->_right)
					{
						RotateL(g);
						parent->_col = BLACK;
						g->_col = RED;
					}
					else// 情况三
					{
						// g
						//  p
						// c
						RotateR(parent);
						RotateL(g);
						cur->_col = BLACK;
						g->_col = RED;
					}
					break;
				}
			}
		}
		// 上面有可能把_root的颜色变为红
		_root->_col = BLACK;
		return make_pair(iterator(newnode), true);
	}

	void RotateL(Node* parent)
	{
		Node* top = parent->_parent;
		Node* right = parent->_right;
		parent->_right = right->_left;
		if (right->_left) right->_left->_parent = parent;
		right->_left = parent;
		parent->_parent = right;
		if (top)// 子树
		{
			if (parent == top->_left) top->_left = right;
			else top->_right = right;
			right->_parent = top;
		}
		else// 完整的树
		{
			_root = right;
			_root->_parent = nullptr;
		}
	}

	void RotateR(Node* parent)
	{
		Node* top = parent->_parent;
		Node* left = parent->_left;
		Node* leftR = left->_right;
		parent->_left = leftR;
		if (leftR) leftR->_parent = parent;
		left->_right = parent;
		parent->_parent = left;
		if (top)
		{
			if (parent == top->_left) top->_left = left;
			else top->_right = left;
			left->_parent = top;
		}
		else
		{
			_root = left;
			_root->_parent = nullptr;
		}
	}

	void _Inorder(Node* root)
	{
		if (root == nullptr)
			return;

		_Inorder(root->_left);
		cout << root->_kv.first << "<=>" << root->_kv.second << endl;
		_Inorder(root->_right);
	}

	void Inorder()
	{
		_Inorder(_root);
	}

	bool _IsBalance(Node* root, int i, int flag)
	{
		if (root == nullptr)
		{
			if (i != flag)
			{
				cout << "errno: 左右子树黑色节点数目不同" << endl;
				return false;
			}
			return true;
		}
		// 红节点时判断父亲
		if (root->_col == RED)
		{
			if (root->_parent->_col == RED)
			{
				cout << "errno: 红-红" << endl;
				return false;
			}
		}
		if (root->_col == BLACK)
		{
			i++;
		}

		return _IsBalance(root->_left, i, flag) 
			&& _IsBalance(root->_right, i, flag);
	}

	bool IsBalance()
	{
		if (_root == nullptr)
		{
			return true;
		}
		if (_root->_col != BLACK)
		{
			return false;
		}
		// 找标准值
		Node* cur = _root;
		int flag = 0;
		while (cur)
		{
			if (cur->_col == BLACK)
			{
				flag++;
			}
			cur = cur->_left;
		}
		int i = 0;
		return _IsBalance(_root, i, flag);
	}

private:
	Node* _root = nullptr;
};
