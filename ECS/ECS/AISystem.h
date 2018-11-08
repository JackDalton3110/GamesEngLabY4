#pragma once
#include "Entity.h"
#include <iostream>
#include <vector>


class AISystem
{
public:
	void addEntity(Entity e);
	void update();
private:
private:
	PositionComponent * posComp;
	std::vector<Entity> m_entities;

	float x = 0;
	float y = 0;
	float speed = 5;

	void BoundaryChecking();
	int screenWidth = 800;
	int screenHeight = 400;

	int direction = 0;
	int index = 0;
};