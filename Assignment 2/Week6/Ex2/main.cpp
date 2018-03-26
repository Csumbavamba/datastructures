#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class Sorting
{
public:
	bool operator () (int left, int right)
	{
		return (left < right);
	}
};

void PrintInt(int number) { cout << number << ", "; }

int main()
{
	std::vector<int> myVector;       
	myVector.push_back(10);   
	myVector.push_back(50);   
	myVector.push_back(53);  
	myVector.push_back(20);  
	myVector.push_back(50);  
	myVector.push_back(25);   
	myVector.push_back(35);   
	myVector.push_back(40);   
	myVector.push_back(40);   
	myVector.push_back(35);   
	myVector.push_back(50);  
	myVector.push_back(31);  
	myVector.push_back(50);

	cout << "Container elements: ";   
	for_each(myVector.begin(), myVector.end(), PrintInt); 
	cout << endl;

	size_t Size = myVector.size();
	cout << Size << " elements in the container." << endl;

	// Test sort, using a functor
	sort(myVector.begin(), myVector.end(), Sorting());

	cout << "After sorting: ";   
	for_each(myVector.begin(), myVector.end(), PrintInt);   
	cout << endl;

	// Test Copy from one container to an other
	std::vector<int> secondVector;
	secondVector.resize(myVector.size());
	copy(myVector.begin(), myVector.end(), secondVector.begin());

	cout << "myVector: "; 
	for_each(myVector.begin(), myVector.end(), PrintInt);  
	cout << endl;      
	cout << "secondVector: "; 
	for_each(secondVector.begin(), secondVector.end(), PrintInt);  
	cout << endl;

	// Test random_shuffle: Requires srand to seed the PRNG... 
	srand(static_cast<int>(time(0)));

	random_shuffle(myVector.begin(), myVector.end());

	cout << "After shuffling: ";    
	for_each(myVector.begin(), myVector.end(), PrintInt);   
	cout << endl;

	system("pause");



	return 0;
}