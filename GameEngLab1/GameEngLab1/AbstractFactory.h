#pragma once
#include <iostream>

//Base
class Character {
public:
	Character() {}
	virtual ~Character() {}
	virtual void draw() = 0;
};


//Concrete family 1
class Player : public Character {
public:
	void draw() {
		std::cout << "Draw Player" << std::endl;
	}
};

//Concrete family 2
class Boss : public Character {
public:
	void draw() {
		std::cout << "Draw Boss" << std::endl;
	}
};


//Creates concrete virtual product
class Factory {
public:
	virtual Character* CreatePlayer() = 0;
	virtual Character* CreateOpponents() = 0;
};

//returns products
class CharacterFactory : public Factory {
public:
	Character * CreatePlayer() {
		return new Player;
	}
	Character * CreateOpponents() {
		return new Boss;
	}
};