#include "Stack.h"
#include "Queue.h"
#include "Deque.h"


int main()
{
	Stack stack;
	stack.TestHarness();

	Queue queue;
	queue.TestHarness();

	Deque deque;
	deque.TestHarness();


	return 0;
}