#include <iostream>
#include <string.h>

#include "BSTree.h"

void test1()
{
	BSTree<string, string> bt;
	bt.Insert("a", "A");
	bt.Insert("b", "B");
	bt.Insert("c", "C");
	bt.InOrder();
	//cout << bt.FindR(3) << endl;
}

int main()
{
	test1();
	return 0;
}