#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> myQueue;

	for (int i = 1; i <= 10; ++i) 
	{
		cout << "Enqueue " << i << " onto the queue." << endl;
		myQueue.push(i);
	}

	while (!myQueue.empty())
	{
		cout << myQueue.front() << " is at the front of the queue, ";
		cout << "Dequeue the front of the queue..." << endl;
		myQueue.pop();
	}

	cout << endl;
	system("pause");

	return 0;
}