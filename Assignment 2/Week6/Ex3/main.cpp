#include <iostream>
#include <string>
#include <map>
#include <algorithm>

void PrintPhoneBookEntry(const std::pair<std::string, int>& entry)
{ 
	std::cout << entry.first << "\'s number is ";    
	std::cout << entry.second << std::endl; 
}

int main()
{
	// Create a map that stores names, and numbers.   
	// std::string's will be the map key.   
	// int will be the value stored at a key

	std::map<std::string, int> phoneBook;

	phoneBook["Leon"] = 64954712;
	phoneBook["Mark"] = 64321234;
	phoneBook["David"] = 61544533;
	phoneBook["Darius"] = 64768521;
	phoneBook["Steffan"] = 64874513;

	// View the entire phonebook: 
	std::map<std::string, int>::iterator iterator = phoneBook.begin();

	while (iterator != phoneBook.end())
	{
		std::cout << iterator->first << "\'s number is ";
		std::cout << iterator->second << std::endl;

		++iterator;
	}

	std::cout << std::endl;

	// Test if Darius is in the phoneBook
	std::cout << "Check the phonebook for Darius..." << std::endl;
	iterator = phoneBook.find("Darius");

	if (iterator != phoneBook.end())
	{
		//Entry exists in the map! 

		std::cout << "Entry : " << (*iterator).first << std::endl;    
		std::cout << "Number: " << (*iterator).second << std::endl;
	}
	else
	{
		std::cout << "Darius not found!" << std::endl;
	}

	// Test for Porter in the phonebook:     
	std::cout << "Check the phonebook for Porter..." << std::endl;
	iterator = phoneBook.find("Porter"); 

	if (iterator != phoneBook.end()) 
	{         
		//Entry exists in the map!      
		std::cout << "Entry : " << iterator->first << std::endl;   
		std::cout << "Number: " << iterator->second << std::endl;     
		// Note the different operator used to access the iterator...  
		// Behaviour is identical to the dot notation above.     
	}
	else
	{
		std::cout << "Porter not found!" << std::endl;
	}

	// Add John to the phoneBook
	std::cout << "Adding Jon's number!" << std::endl;
	phoneBook["John"] = 35612382;

	// Remove Leon from the phonebook:   
	std::cout << "Removing Leon's number!" << std::endl; 
	phoneBook.erase("Leon");

	// Update David's phonenumber   
	std::cout << "Updating David's number!" << std::endl; 
	phoneBook["David"] = 64565612;

	// Add Porter to the phonebook:  
	std::cout << "Adding Porters's number!" << std::endl;   
	phoneBook["Porter"] = 64464646; 

	std::cout << std::endl;

	// View the entire phonebook, using for_each: 
	for_each(phoneBook.begin(), phoneBook.end(), PrintPhoneBookEntry);

	system("pause");

	return 0;
}