#pragma once
#include "CNode.h"

class DoubleLinkedList
{
private:
	CNode *root;
public:
	DoubleLinkedList();
	~DoubleLinkedList();

	void InsertAtTheFront(int value);

	void InsertInTheMiddle(int value, int position);

	void InsertAtTheEnd(int value);

	void Delete(int value);

	bool Search(int value);

	void Display();
	
	void TestHarness();
};

