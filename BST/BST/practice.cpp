#include <iostream>

using namespace std;

namespace yyh
{
	template <class K, class V>
	struct BSTreeNode
	{
		BSTreeNode(const K& key, const V& val)
			: left(nullptr)
			, right(nullptr)
		{
			_key = key;
			_val = val;
		}
		BSTreeNode<K, V>* left;
		BSTreeNode<K, V>* right;
		K _key;
		V _val;
	};

	template<class K, class V>
	class BSTree
	{
		typedef BSTreeNode<K, V> Node;
	public:
		bool Insert(const K& key, const V& value)
		{
			if (_root == nullptr)
			{
				_root = new Node(key, value);
				return true;
			}
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->left;
				}
				else
				{
					return false;
				}
			}
			cur = new Node(key, value);
			if (parent->_key < key)
			{
				parent->right = cur;
			}
			else
			{
				parent->left = cur;
			}
			return true;
		}

		Node* Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					cur = cur->right;
				}
				else if (cur->_key > key)
				{
					cur = cur->left;
				}
				else
				{
					return cur;
				}
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->left;
				}
				else
				{
					if (!cur->left)
					{
						if (cur == _root)
						{
							_root = cur->right;
						}
						else
						{
							if (cur == parent->left) parent->left = cur->right;
							else parent->right = cur->right;
						}
						delete cur;
					}
					else if (!cur->right)
					{
						if (cur == _root)
						{
							_root = cur->left;
						}
						else
						{
							if (cur == parent->left) parent->left = cur->left;
							else parent->right = cur->left;
						}
						delete cur;
					}
					else
					{
						Node* parent = cur;
						Node* minRight = cur->right;
						while (minRight->left)
						{
							parent = minRight;
							minRight = minRight->left;
						}
						cur->_key = minRight->_key;
						cur->_val = minRight->_val;
						if (minRight == parent->left) parent->left = minRight->right;
						else parent->right = minRight->right;
						delete minRight;
					}
					return true;
				}
			}
			return false;
		}

		void _InOrder(Node* root)
		{
			if (!root) return;
			_InOrder(root->left);
			cout << root->_val << " ";
			_InOrder(root->right);
		}
		void InOrder()
		{
			_InOrder(_root);
		}
	private:
		Node* _root = nullptr;
	};

	void TestBSTree()
	{
		BSTree<string, string> dict;
		dict.Insert("insert", "²åÈë");
		dict.Insert("erase", "É¾³ý");
		dict.Insert("left", "×ó±ß");
		dict.Insert("string", "×Ö·û´®");

		string str;
		while (cin >> str)
		{
			auto ret = dict.Find(str);
			if (ret)
			{
				cout << str << ":" << ret->_val << endl;
			}
			else
			{
				cout << "µ¥´ÊÆ´Ð´´íÎó" << endl;
			}
		}

		string strs[] = { "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Ó£ÌÒ", "Æ»¹û", "Ó£ÌÒ", "Æ»¹û", "Ó£ÌÒ", "Æ»¹û" };
		// Í³¼ÆË®¹û³öÏÖµÄ´Î
		BSTree<string, int> countTree;
		for (auto str : strs)
		{
			auto ret = countTree.Find(str);
			if (ret == NULL)
			{
				countTree.Insert(str, 1);
			}
			else
			{
				ret->_val++;
			}
		}
		countTree.InOrder();
	}
}

int main()
{
	yyh::TestBSTree();
	return 0;
}