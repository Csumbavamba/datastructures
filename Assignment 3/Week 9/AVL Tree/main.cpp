#include <iostream>

#include "AVLTree.h"
#include "Node.h"

int main()
{
	AVLTree tree;

	tree.InsertNode(7);
	tree.InsertNode(8);
	tree.InsertNode(6);
	tree.InsertNode(5);
	tree.InsertNode(4);

	tree.BalanceTree();

	system("pause");

	std::cout << std::endl;

	tree.DisplayInOrder(tree.GetRoot());

	system("pause");

	return 0;
}