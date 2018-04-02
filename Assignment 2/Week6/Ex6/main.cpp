#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

class Character
{
public:
	Character()
	{
	}

	Character(std::string name, std::string race, int level, std::string playerID)
		: name(name)
		, race(race)
		, level(level)
		, ID(playerID)
	{
	}

	void PrintValues()
	{
		cout << "Name: " << name << endl;
		cout << "Race: " << race << endl;
		cout << "Level: " << level << endl;
		cout << "ID: " << ID << endl;
	}



public:
	std::string name;
	std::string race;
	int level;
	std::string ID;
};

// Create a method for creating a character
void CreateCharacter()
{
	std::string input;
	Character * testChara = new Character();

	cout << "Give Character Name> " << endl;
	getline(cin, input);
	testChara->name = input;
	system("cls");


	cout << "Give Character Race> " << endl;
	getline(cin, input);
	testChara->race = input;
	system("cls");

	cout << "Give Character Level> " << endl;
	getline(cin, input);
	testChara->level = std::stoi(input); // Convert string to int
	system("cls");

	cout << "Give Character ID> " << endl;
	getline(cin, input);
	testChara->ID = input;
	system("cls");


}


int main()
{
	bool creationOver = false;
	std::multimap <std::string, Character> myMap;

	// Create characters
	while (!creationOver)
	{
		std::string input;
		Character * testChara = new Character();

		cout << "Give Character Name> " << endl;
		getline(cin, input);
		testChara->name = input;
		system("cls");

		cout << "Give Character Race> " << endl;
		getline(cin, input);
		testChara->race = input;
		system("cls");

		cout << "Give Character Level> " << endl;
		getline(cin, input);
		testChara->level = std::stoi(input); // Convert string to int
		system("cls");

		cout << "Give Character ID> " << endl;
		getline(cin, input);
		testChara->ID = input;
		system("cls");

		// Insert to map
		myMap.insert(std::pair<std::string, Character>(testChara->ID, *testChara));
		delete testChara;

		cout << "Wanna create more characters? Enter Y/y if yes" << endl;
		getline(cin, input);

		if (input != "y" || input != "Y")
		{
			creationOver = true;
		}
	}

	// When creation over, print characters on screen
	std::map<std::string, Character>::iterator iterator = myMap.begin();

	while (iterator != myMap.end())
	{
		Character tempCharacter = iterator->second;

		tempCharacter.PrintValues();
		iterator++;
	}

	system("pause");



	return 0;
}