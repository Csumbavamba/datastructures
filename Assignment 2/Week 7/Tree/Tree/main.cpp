#include <iostream>

#include "Node.h"
#include "Tree.h"

int main()
{
	Tree tree;

	tree.InsertNode(5);
	tree.InsertNode(3);
	tree.InsertNode(11);
	tree.InsertNode(9);
	tree.InsertNode(7);
	tree.InsertNode(8);
	tree.InsertNode(6);
	tree.InsertNode(5);

	tree.DeleteNode(8);


	tree.DisplayPreOrder(tree.GetRoot());

	system("pause");

	return 0;
}