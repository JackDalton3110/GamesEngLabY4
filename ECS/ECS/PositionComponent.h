#pragma once
#include "Component.h"

class PositionComponent : public Component
{
public:
	PositionComponent() : health(100) {}

	int getHealth() { return health; }
	void setHealth(int health) { this->health = health; }

private:
	int health;
};