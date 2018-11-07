#pragma once
#include "Entity.h"
#include <iostream>
#include <vector>


class AISystem
{
	std::vector<Entity> entities;

public:
	void addEntity(Entity e) { entities.push_back(e); }
	void update();
private:
private:
	PositionComponent * posComp;
	std::vector<Entity> m_entities;

	float x = 0;
	float y = 0;
	float speed = 10;

	void BoundaryChecking();
	int screenWidth = 1280;
	int screenHeight = 720;

	int direction = 0;
};