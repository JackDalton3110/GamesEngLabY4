#pragma once
#include "Entity.h"
#include <iostream>
#include <vector>

class ControlSystem
{
	std::vector<Entity> entities;

public:
	void addEntity(Entity e) { entities.push_back(e); }
	void update() {
		std::cout << "ControlSystem Update" << std::endl;
		for (Entity &entity : entities)
		{
			for (Component* component : entity.getComponents())
			{
				if (component->getID() == 3)
				{
					std::cout << "Checking Control component" << std::endl;
				}
			}
		}
	}
};