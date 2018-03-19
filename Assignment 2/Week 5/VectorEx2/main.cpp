#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Prototype
string * PointToElement(vector<string>* const vector, int element);

int main()
{
	vector<string> vectorInventory;

	vectorInventory.push_back("sword");
	vectorInventory.push_back("shield");
	vectorInventory.push_back("armour");

	// Display the strings inside the vector
	cout << "Sending the object pointed to by returned pointer: " << endl; 
	cout << *(PointToElement(&vectorInventory, 0)) << endl << endl;

	// Assign pointer to another -- inexpensive assignment
	cout << "Assigning the returned pointer to an other pointer" << endl;

	string * newPointer = PointToElement(&vectorInventory, 1);

	cout << "Object that new pointer is pointing to: " << endl << endl;
	cout << *newPointer << endl << endl;

	// Copies a string -- expensive assignment
	cout << "Assigning object pointed by pointer to a string object." << endl;

	string newString = *(PointToElement(&vectorInventory, 2));

	cout << "The object that was instantiated holds the following object: " << endl;
	cout << newString << endl;

	//  Alter the string object through a returned pointer

	cout << "Altering an object through a returned pointer." << endl; 
	*newPointer = "Healing Potion."; 
	cout << "Sending the altered object to cout" << endl; 
	cout << vectorInventory[1] << endl;

	system("pause");

	return 0;
}

string * PointToElement(vector<string>* const vector, int element)
{
	return (&(*vector)[element]);
}