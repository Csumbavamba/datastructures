#include <iostream>

#include "AVLTree.h"
#include "Node.h"

int main()
{
	AVLTree tree;

	tree.InsertNode(8);
	tree.InsertNode(7);
	tree.InsertNode(10);
	tree.InsertNode(9);
	tree.InsertNode(6);
	tree.InsertNode(15);
	tree.InsertNode(14);
	tree.InsertNode(17);
	tree.InsertNode(13);

	system("pause");

	std::cout << std::endl;

	tree.DisplayInOrder(tree.GetRoot());

	system("pause");

	return 0;
}