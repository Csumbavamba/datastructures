#include <iostream>

#include "BinaryHeap.h"
#include "Node.h"

int main()
{
	BinaryHeap heap;

	heap.Insert(1);
	heap.Insert(3);
	heap.Insert(5);

	heap.PrintHeap();
	system("pause");

	heap.Insert(15);
	heap.Insert(14);
	// heap.Insert(30);
	// heap.Insert(16);

	heap.RemoveFirst();

	heap.PrintHeap();

	system("pause");


	return 0;
}