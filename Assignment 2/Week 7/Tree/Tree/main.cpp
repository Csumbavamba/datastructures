#include <iostream>

#include "Node.h"
#include "Tree.h"

int main()
{
	Tree tree;

	tree.InsertNode(5);
	tree.InsertNode(3);
	tree.InsertNode(11);

	tree.DeleteNode(3);

	tree.DisplayTree();

	system("pause");

	return 0;
}