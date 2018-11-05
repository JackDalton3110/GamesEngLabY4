#pragma once
#include <iostream>
#include "Component.h"

class HealthComponent : public Component
{
public:
	HealthComponent() : health(100){}

	int getHealth() { return health; }
	int getID() { return id; }
	void setHealth(int health) { this->health = health; }

private:
	int health;
	int id = 2;
};
