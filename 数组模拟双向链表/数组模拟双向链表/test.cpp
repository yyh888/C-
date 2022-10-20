#include <iostream>
using namespace std;

const int MAX = 10;

class mylist
{
public:
	mylist()
		: index(2)
	{
		// 0λ�ñ�ʾͷ��1λ�ñ�ʾβ
		l[1] = 0;
		r[0] = 1;
	}

	// ��pos���ұ߲���
	void insert(int pos, int x)
	{
		// �Ȳ��뵽e��
		e[index] = x;
		// �ĸ���
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

	// ���������ɾ��
	void pop(int pos)
	{
		// ���һ���
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

	// ��posλ�õ�����Ų������/�ұ�
	void move(char ch, int pos)
	{
		// ��ɾ��posλ��(l��r)
		pop(pos);
		// ����posλ�õ�l��r
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
	int e[MAX];// �ڵ�����
	int l[MAX];// ��¼��ǰ�ڵ����ڵ�
	int r[MAX];// ��¼��ǰ�ڵ���ҽڵ�
	int index;// ��¼e��һ��Ҫ�����λ��
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