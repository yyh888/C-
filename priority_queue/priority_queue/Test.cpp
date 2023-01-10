#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

void adjustdown(int parent)
{
    int child = 2 * parent + 1;
    while (child < v.size())
    {
        if (child + 1 < v.size() && v[child] < v[child + 1])
        {
            child++;
        }
        if (v[parent] < v[child])
        {
            swap(v[child], v[parent]);
            parent = child;
            child = 2 * parent + 1;
        }
        else break;
    }
}

int main()
{
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	v.push_back(2);
	for (int i = (v.size() - 1 - 1) / 2; i >= 0; i--)
	{
		adjustdown(i);
	}
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
	return 0;
}