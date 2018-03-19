#pragma once

#include "CNode.h"

class Queue
{
	CNode * front;
	CNode * end; // root
public:
	Queue();
	~Queue();

	void Enqueue(int data);
	void Dequeue();
	int Peek();
	bool IsEmpty();
	void PrintQueueMembers();
	void TestHarness();

};

