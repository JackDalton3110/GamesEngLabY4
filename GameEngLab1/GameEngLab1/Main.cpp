#include "AbstractFactory.h"
#include <iostream>
#include <vector>

int main() {
	Factory* factory = new CharacterFactory;
	std::vector<Character*> characters; //create vector
	characters.push_back(factory->CreatePlayer());//create player product 
	characters.push_back(factory->CreateOpponents()); //create Boss product

	for (int i = 0; i < characters.size(); i++) 
	{
		characters[i]->draw();
	}
	std::cin.get();
}