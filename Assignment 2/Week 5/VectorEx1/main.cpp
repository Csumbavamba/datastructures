#include <iostream>
#include <vector>
#include <algorithm>

// using namespace std;

int main()
{
	// Create Vector (array) to store ints
	std::vector<int> myIntVector;

	// Add values at the end of the vector
	myIntVector.push_back(1977);
	myIntVector.push_back(1980);
	myIntVector.push_back(1983);

	for (unsigned int i = 0; i < myIntVector.size(); i++)
	{
		std::cout << "A great year in cinemas: " << myIntVector[i] << std::endl;
	}

	// Checks if not empty. 
	if (!myIntVector.empty()) 
	{ 
		// Clear vector. 
		myIntVector.clear(); 

		std::cout << std::endl; 
		std::cout << "myIntVector has been cleared." << std::endl << std::endl;
	}

	// Creates another vector to store integers. 
	std::vector<int> myOtherIntVector;

	// Add values at the end of the vector. 
	myOtherIntVector.push_back(10); 
	myOtherIntVector.push_back(25); 
	myOtherIntVector.push_back(35); 
	
	if (myIntVector != myOtherIntVector)
	{
		myIntVector.push_back(20);
	}
	

	for (unsigned int i = 0; i < myIntVector.size(); i++)
	{
		std::cout << myIntVector[i] << std::endl << std::endl;
	}
	
	system("pause");

	


	return 0;
}