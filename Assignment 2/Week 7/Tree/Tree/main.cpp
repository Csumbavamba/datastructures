#include <iostream>

#include "Node.h"
#include "Tree.h"

void TestHarness()
{
	Tree tree;

	std::cout << "Inserting nodes - 5, 3, 11, 9, 7, 8, 6, 5." << std::endl;

	tree.InsertNode(5);
	tree.InsertNode(3);
	tree.InsertNode(11);
	tree.InsertNode(9);
	tree.InsertNode(7);
	tree.InsertNode(8);
	tree.InsertNode(6);
	tree.InsertNode(5);

	std::cout << "PreOrder: " << std::endl;
	tree.DisplayPreOrder(tree.GetRoot());

	std::cout << std::endl << std::endl;

	std::cout << "InOrder: " << std::endl;
	tree.DisplayInOrder(tree.GetRoot());

	std::cout << std::endl << std::endl;

	std::cout << "PostOrder: " << std::endl;
	tree.DisplayPostOrder(tree.GetRoot());

	std::cout << std::endl << std::endl;


	system("pause");

	std::cout << "Deleting value 8 from tree" << std::endl;

	std::cout << std::endl;
	tree.DeleteNode(8);

	std::cout << "PreOrder: " << std::endl;
	tree.DisplayPreOrder(tree.GetRoot());

	std::cout << std::endl << std::endl;

	std::cout << "InOrder: " << std::endl;
	tree.DisplayInOrder(tree.GetRoot());

	std::cout << std::endl << std::endl;

	std::cout << "PostOrder: " << std::endl;
	tree.DisplayPostOrder(tree.GetRoot());

	std::cout << std::endl << std::endl;

	system("pause");
}

int main()
{
	TestHarness();

	return 0;
}