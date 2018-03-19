#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> myStack;

	for (int i = 1; i <= 10; ++i) 
	{
		cout << "Pushing " << i << " onto the stack." << endl;
		myStack.push(i);
	}

	while (!myStack.empty())
	{
		cout << myStack.top() << " is at the top of the stack, ";
		cout << "Popping the stack..." << endl;
		myStack.pop();
	}

	cout << endl;
	system("pause");

	return 0;
}