#pragma once

using namespace std;

template <class K, class V>
struct BSTreeNode
{
	BSTreeNode(K x, V y)
		: _left(nullptr)
		, _right(nullptr)
		, _key(x)
		, _val(y)
	{}
	BSTreeNode<K, V>* _left;
	BSTreeNode<K, V>* _right;
	K _key;
	V _val;
};

template <class K, class V>
class BSTree
{
	typedef BSTreeNode<K, V> Node;
public:
	bool Insert(const K& x, const V& y)
	{
		if (_root == nullptr)
		{
			_root = new Node(x, y);
			return true;
		}
		else
		{
			Node* cur = _root, *parent = nullptr;
			while (cur)
			{
				if (cur->_key < x)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > x)
				{
					parent = cur;
					cur = cur->_left;
				}
				else return false;
			}
			cur = new Node(x, y);
			if (parent->_key > x) parent->_left = cur;
			else parent->_right = cur;
			return true;
		}
	}

	Node* Find(const K& x)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > x)
			{
				cur = cur->_left;
			}
			else if (cur->_key < x)
			{
				cur = cur->_right;
			}
			else return cur;
		}
		return nullptr;
	}

	void InOrder(Node* root)
	{
		if (!root) return;
		InOrder(root->_left);
		cout << root->_key << " ";
		InOrder(root->_right);
	}

	void InOrder()
	{
		InOrder(_root);
	}

private:

	void Destory(Node*& root)
	{
		if (root == nullptr) return;
		Destory(root->_left);
		Destory(root->_right);
		delete root;
	}

	Node* _root = nullptr;
};