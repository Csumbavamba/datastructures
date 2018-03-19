#pragma once
#include "CNode.h"

class Deque
{
private:
	CNode * front;
	CNode * end; // root
public:
	Deque();
	~Deque();

	void EnqueueAtFront(int data);
	void EnqueueAtEnd(int data);
	void DequeueAtFront();
	void DequeueAtEnd();
	int PeekAtFront();
	int PeekAtEnd();
	bool IsEmpty();
	void PrintDequeMembers();
	void TestHarness();
};

