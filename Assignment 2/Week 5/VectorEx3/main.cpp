#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	// Declare a string vector. 
	vector<string> playersVector; 
	// Declare a string vector iterator. 
	vector<string>::iterator iterator; 

	// Add some elements to the vector. 
	playersVector.push_back("Darius");
	playersVector.push_back("David");
	playersVector.push_back("Porter");
	playersVector.push_back("Leon");
	playersVector.push_back("Mark");
	playersVector.push_back("Steffan");

	// This is the old way, which is similar to getting data 
	// out of arrays. 
	cout << endl << endl; 
	cout << "C/C++ Style" << endl; 
	cout << "-----------" << endl; 

	for (unsigned int i = 0; i < playersVector.size(); i++) 
	{ 
		cout << playersVector[i] << endl; 
	}

	// Using the iterator. 
	cout << endl << endl; 
	cout << "STL Iterator Style" << endl; 
	cout << "------------------" << endl;

	for (iterator = playersVector.begin();
		iterator != playersVector.end();
		iterator++)
	{
		// Dereference the string vector iterator in a 
		// similiar fashion to how we dereference a pointer.   
		cout << *iterator << endl;
	}

	system("pause");

	return 0;
}