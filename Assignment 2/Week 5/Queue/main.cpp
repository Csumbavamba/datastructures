#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	/*
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
	*/
	vector<int> myVector;

	for (int i = 1; i <= 10; ++i)
	{
		cout << "Enqueue " << i << " onto the queue." << endl;
		myVector.push_back(i);
	}

	cout << endl;
	system("pause");


	std::vector<int>::iterator newEnd = std::remove(myVector.begin(), myVector.end(), 2);

	for (unsigned int i = 0; i < myVector.size(); i++)
	{
		std::cout << "A great year in cinemas: " << myVector[i] << std::endl;
	}

	system("pause");

	return 0;
}