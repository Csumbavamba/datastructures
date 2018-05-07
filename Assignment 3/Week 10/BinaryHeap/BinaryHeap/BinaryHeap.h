#pragma once

#include <vector>

class Node;

enum ChildrenState
{
	Default,
	NoChildren,
	OneChild,
	TwoChildren
};

class BinaryHeap
{
private:

	int heapSize;
	std::vector<Node*> heap;
	Node * root;

public:

	BinaryHeap();
	~BinaryHeap();

	void Insert(int nodeValue);

	void SortInsertion();
	int GetParentValue(int nodePosition) { return nodePosition / 2; }
	void SwapNodeValue(Node * parent, Node * child);

	void RemoveFirst();
	ChildrenState DefineChildrenState(int nodePosition);


	void PrintHeap();


};

