#pragma once
#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib> 

using namespace std;

template <class K, class V>
struct AVLNode
{
	AVLNode(const pair<K, V>& kv)
		: _kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
	{}

	pair<K, V> _kv;
	AVLNode<K, V>* _left;
	AVLNode<K, V>* _right;
	AVLNode<K, V>* _parent;
	int _bf;// 平衡因子
};


template <class K, class V>
class AVLTree
{
	typedef AVLNode<K, V> Node;
public:
	bool insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
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
		// 更新平衡因子
		while (parent)
		{
			if (cur == parent->_left) parent->_bf--;
			else parent->_bf++;
			if (parent->_bf == 0) break;
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// 旋转
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					// 左单旋
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1)
				{
					// 右单旋
					RotateR(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					// 左右双旋
					RotateLR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					// 右左双旋
					RotateRL(parent);
				}
				break;
			}
			else
			{
				cout << "结构出错" << endl;
				assert(false);
			}
		}
		return true;
	}

	void RotateL(Node* parent)
	{
		Node* top = parent->_parent;
		Node* right = parent->_right;
		// 20的左边调整到10的右边
		parent->_right = right->_left;
		if (right->_left) right->_left->_parent = parent;
		// 10变成20的左边，20做根
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
		// 更新平衡因子
		parent->_bf = right->_bf = 0;
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
		parent->_bf = left->_bf = 0;
	}

	void RotateLR(Node* parent)
	{
		Node* left = parent->_left;
		Node* right = left->_right;
		int bf = right->_bf;// 提前记录
		RotateL(left);
		RotateR(parent);
		if (bf == -1)// 左子树新增
		{
			left->_bf = 0;
			right->_bf = 0;
			parent->_bf = 1;
		}
		else if (bf == 1)// 右子树新增
		{
			left->_bf = -1;
			right->_bf = 0;
			parent->_bf = 0;
		}
		else if (bf == 0)// 自己就是新增
		{
			left->_bf = right->_bf = parent->_bf = 0;
		}
		else assert(false);
	}

	void RotateRL(Node* parent)
	{
		Node* right = parent->_right;
		Node* left = right->_left;
		int bf = left->_bf;
		RotateR(right);
		RotateL(parent);
		if (bf == -1)
		{
			parent->_bf = 0;
			left->_bf = 0;
			right->_bf = 1;
		}
		else if (bf == 1)
		{
			right->_bf = 0;
			left->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf == 0)
		{
			left->_bf = right->_bf = parent->_bf = 0;
		}
		else assert(false);
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

	int Height(Node* root)
	{
		if (!root)
		{
			return 0;
		}
		int lh = Height(root->_left) + 1;
		int rh = Height(root->_right) + 1;
		return max(lh, rh);
	}

	bool IsBalance(Node* root)
	{
		if (!root)
		{
			return true;
		}
		int lh = Height(root->_left);
		int rh = Height(root->_right);
		if (rh - lh != root->_bf)
		{
			cout << root->_kv.first << ":";
			cout << root->_bf << ":";
			cout << "平衡因子出错" << endl;
			return false;
		}
		if (abs(rh - lh) > 1)
		{
			return false;
		}
		return IsBalance(root->_left) && IsBalance(root->_right);
	}

	bool IsBalance()
	{
		return IsBalance(_root);
	}
private:
	Node* _root = nullptr;
};

void test()
{
	const int N = 100000;
	AVLTree<int, int> tt;
	srand(time(0));
	for (int i = 0; i < N; i++)
	{
		int x = rand();
		tt.insert(make_pair(x, x));
	}
	//tt.Inorder();
	cout << tt.IsBalance() << endl;
}