#pragma once
#include "Entity.h"
#include <iostream>
#include <vector>

class HealthSystem
{
	std::vector<Entity> entities;

public:
	void addEntity(Entity e){}
	void update() {
		std::cout << "HealthSystem Update" << std::endl;
		for (int i = 0; i < entities.size(); i++)
		{

		}
	}
};

class PositionSystem
{
	std::vector<Entity> entities;

public:
	void addEntity(Entity e) {}
	void update() {
		std::cout << "PositionSystem Update" << std::endl;
		for (int i = 0; i < entities.size(); i++)
		{

		}
	}
};