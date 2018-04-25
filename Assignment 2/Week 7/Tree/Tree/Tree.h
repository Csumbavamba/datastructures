#pragma once
#include "Node.h"
#include <vector>

class Tree
{
private:
	Node *root;
public:
	Tree();
	~Tree();
	
	Node * GetRoot();

	void InsertNode(int nodeValue);

	void DeleteNode(int nodeValue);

	Node* FindNode(int nodeValue);

	void DisplayPreOrder(Node * currentNode);
	void DisplayInOrder(Node * currentNode);
	void DisplayPostOrder(Node * currentNode);
	
};

