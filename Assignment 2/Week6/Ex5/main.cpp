/*
	Create a map - that takes in a Player (class) and a number ID
	Create random players for testing
		Name, race, level
*/



#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

class Character
{
public:
	Character(std::string name, std::string race, int level)
		: name(name)
		, race(race)
		, level(level)
	{
	}

	// THESE ARE PROBABLY BAD
	std::ostream operator <<(Character character)
	{
		std::cout << character.name << ", " << character.race << ", " << character.level;
	}

	// THESE ARE PROBABLY BAD
	operator std::string()
	{
		return name;
	}


private:
	std::string name;
	std::string race;
	int level;
};

int main()
{
	const Character Bela("Bela", "Human", 1);
	const Character Adam("Adam", "Human", 10);
	const Character Buksi("Buksi", "Dog", 3);

	std::map<Character, int> myMap;

	myMap.insert(make_pair(Bela, 1));
	myMap.insert(make_pair(Adam, 2));
	myMap.insert(make_pair(Buksi, 3));

	std::map<Character, int>::iterator iterator = myMap.begin();

	while (iterator != myMap.end())
	{
		// std::cout << iterator->first; // --> This generates error
		std::cout << " - " << iterator->second << std::endl;
		iterator++;
	}

	system("pause");



	return 0;
}