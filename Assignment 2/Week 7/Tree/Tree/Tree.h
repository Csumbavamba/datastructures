#pragma once
#include "Node.h"

class Tree
{
private:
	Node *root;
public:
	Tree();
	~Tree();

	void InsertNode(int nodeValue);

	void DeleteNode(int nodeValue);

	Node* FindNode(int nodeValue);

	void DisplayTree();
	
};

