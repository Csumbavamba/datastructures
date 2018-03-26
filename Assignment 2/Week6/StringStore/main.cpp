/*
	User can enter a single word
	Store each word in a string
	Place the string into a linkedlist
	Save the linked list to a text file
*/

#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include <string>


void PrintString(std::string word)
{
	std::cout << word << std::endl;
}

int main()
{
	std::list<std::string> stringList;
	
	std::string temporaryString;

	
	for (int i = 1; i < 6; i++)
	{
		// Ask the user to enter a single word
		std::cout << "Please enter a word you would like to save - " << i << ": ";
		std::cin >> temporaryString;

		// Place the  string into the linkedlist
		stringList.push_back(temporaryString);
	}

	// Draw the string elements
	// std::for_each(stringList.begin(), stringList.end(), PrintString);

	/// Print the elements to a text file
	std::ofstream outFile;

	// Create testText.txt
	std::string outputFileName = "testText.txt";
	outFile.open(outputFileName);
	
	std::list<std::string>::iterator iterator = stringList.begin();

	if (outFile.is_open())
	{
		while (iterator != stringList.end())
		{
			// Write list element to file
			outFile << *iterator << std::endl;
			iterator++;
		}

		outFile.close();
		
	}
	else
	{
		std::cout << "Could not create file: " << outputFileName << std::endl;
	}

	
	return 0;
}