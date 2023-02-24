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

template <class K, class V>
struct RBTreeNode
{
	RBTreeNode(const pair<K, V>& kv)
		: _kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _col(RED)
	{}

	pair<K, V> _kv;
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	Colour _col;
};

template <class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	bool insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (kv.first < cur->_kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (kv.first > cur->_kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else return false;
		}
		cur = new Node(kv);
		if (kv.first < parent->_kv.first)
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
			// ��g �� u
			Node* g = parent->_parent;
			if (parent == g->_left)
			{
				Node* u = g->_right;
				// ���һ u������Ϊ��
				if (u && u->_col == RED)
				{
					parent->_col = u->_col = BLACK;
					g->_col = RED;
					// �������ϴ���
					cur = g;
					parent = cur->_parent;
				}
				else // ������������
				{
					if (cur == parent->_left)// �����
					{
						//   g
						//  p
						// c
						RotateR(g);
						parent->_col = BLACK;
						g->_col = RED;
					}
					else// �����
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
				// ���һ
				if (u && u->_col == RED)
				{
					u->_col = parent->_col = BLACK;
					g->_col = RED;
					cur = g;
					parent = cur->_parent;
				}
				else
				{
					// �����
					// g
					//  p
					//   c
					if (cur == parent->_right)
					{
						RotateL(g);
						parent->_col = BLACK;
						g->_col = RED;
					}
					else// �����
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
		// �����п��ܰ�_root����ɫ��Ϊ��
		_root->_col = BLACK;
		return true;
	}

	void RotateL(Node* parent)
	{
		Node* top = parent->_parent;
		Node* right = parent->_right;
		parent->_right = right->_left;
		if (right->_left) right->_left->_parent = parent;
		right->_left = parent;
		parent->_parent = right;
		if (top)// ����
		{
			if (parent == top->_left) top->_left = right;
			else top->_right = right;
			right->_parent = top;
		}
		else// ��������
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
				cout << "errno: ����������ɫ�ڵ���Ŀ��ͬ" << endl;
				return false;
			}
			return true;
		}
		// ��ڵ�ʱ�жϸ���
		if (root->_col == RED)
		{
			if (root->_parent->_col == RED)
			{
				cout << "errno: ��-��" << endl;
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
		// �ұ�׼ֵ
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

void test()
{
	RBTree<int, int> bb;
	const int N = 10000;
	srand(time(0));
	for (int i = 0; i < N; i++)
	{
		size_t x = rand();
		bb.insert(make_pair(x, x));
	}
	/*int a[] = { 16, 3, 7, 11, 9, 26, 18, 14};
	for (auto e : a)
	{
		bb.insert(make_pair(e, e));
	}*/
	cout << bb.IsBalance();
}