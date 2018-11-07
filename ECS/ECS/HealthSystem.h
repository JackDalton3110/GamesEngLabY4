#pragma once
#include "Entity.h"
#include <iostream>
#include <vector>

class HealthSystem
{
	std::vector<Entity> entities;

public:
	void addEntity(Entity e) { entities.push_back(e); }
	void update() 
	{
		std::cout << "HealthSystem Update" << std::endl;
		for (Entity &entity : entities)
		{
			for (Component* component : entity.getComponents())
			{
				if (component->getID() == 2)
				{
					int health = dynamic_cast<HealthComponent*>(component)->getHealth();

					std::cout << "Checking Health component" << std::endl;
				}
			}
		}
	}
};
