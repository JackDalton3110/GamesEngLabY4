#pragma once
#include <vector>
#include "Component.h"

class PositionComponent : public Component
{
public:
	PositionComponent() : posX(200.f), posY(200.f) {};

	float getPosX() { return posX; }
	float getPosY() { return posY; }
	void setPos(float x, float y) { this->posX = x; this->posY = y; }
	int getID() { return id; }

private:
	float posX;
	float posY;
	int id = 1;
};