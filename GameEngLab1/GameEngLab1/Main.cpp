#include "AbstractFactory.h"
#include <iostream>
#include <vector>

int main() {
	Factory* factory = new CharachterFactory;
	std::vector<Character*> characters;
	characters.push_back(factory->CreatePlayer());
	characters.push_back(factory->CreateOpponents());

	for (int i = 0; i < characters.size(); i++) {

		characters[i]->draw();

	}

	std::cin.get();
}