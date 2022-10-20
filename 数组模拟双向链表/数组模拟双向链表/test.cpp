#include <iostream>
using namespace std;

const int MAX = 10;

class mylist
{
public:
	mylist()
		: index(2)
	{
		// 0位置表示头，1位置表示尾
		l[1] = 0;
		r[0] = 1;
	}

	// 在pos的右边插入
	void insert(int pos, int x)
	{
		// 先插入到e中
		e[index] = x;
		// 四根线
		l[index] = pos;
		r[index] = r[pos];
		l[r[pos]] = index;
		r[pos] = index;
		index++;
	}

	void push_back(int x)
	{
		e[index] = x;
		l[index] = l[1];
		r[index] = 1;
		r[l[1]] = index;
		l[1] = index;
		index++;
	}

	// 并不是真的删除
	void pop(int pos)
	{
		// 左右互连
		r[l[pos]] = r[pos];
		l[r[pos]] = l[pos];
	}

	void print()
	{
		for (int i = r[0]; i != 1; i = r[i])
		{
			cout << e[i] << " ";
		}
		cout << endl;
	}

	// 将pos位置的数字挪到最左/右边
	void move(char ch, int pos)
	{
		// 先删除pos位置(l和r)
		pop(pos);
		// 设置pos位置的l和r
		if (ch == 'L')
		{
			l[pos] = 0;
			r[pos] = r[0];
			l[r[0]] = pos;
			r[0] = pos;
		}
		else
		{
			l[pos] = l[1];
			r[pos] = 1;
			r[l[1]] = pos;
			l[1] = pos;
		}
	}

private:
	int e[MAX];// 节点数据
	int l[MAX];// 记录当前节点的左节点
	int r[MAX];// 记录当前节点的右节点
	int index;// 记录e下一个要插入的位置
};


int main()
{
	mylist list;
	
	/*for (int i = 1; i <= 5; i++)
	{
		list.insert(i - 1, i);
	}*/
	int n = 5;
	for (int i = 1; i <= n; i++)
	{
		list.push_back(i);
	}
	list.print();
	return 0;
}