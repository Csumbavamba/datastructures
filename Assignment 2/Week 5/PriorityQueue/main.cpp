#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Comparison
{
public:
	bool operator() (const int& first, const int& second)
	{
		return (first < second);
	}
};

int main()
{
	priority_queue<int, vector<int>, Comparison> myPriorityQueue;

	for (int i = 1; i <= 10; ++i) 
	{
		cout << "Enqueue " << i << " onto the priority queue." << endl;
		myPriorityQueue.push(i);
	}

	while (!myPriorityQueue.empty())
	{
		cout << myPriorityQueue.top() << " is at the front of the priority queue, ";
		cout << "Dequeue the front of the queue..." << endl;
		myPriorityQueue.pop();
	}

	cout << endl;

	system("pause");

	return 0;
}