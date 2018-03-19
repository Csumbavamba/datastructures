#pragma once
#include "CNode.h"

class Stack
{
private:
	CNode * root;

public:
	Stack();
	~Stack();

	void Push(int data);
	void Pop();
	int Peek();
	bool IsEmpty();
	void PrintStackMembers();

	void TestHarness();

};

