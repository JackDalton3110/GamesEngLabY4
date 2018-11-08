#pragma once
#include "Entity.h"
#include <iostream>
#include <vector>

class HealthSystem
{
	std::vector<Entity> entities;
	HealthComponent *healthComp;

public:
	void addEntity(Entity e) { entities.push_back(e); }
	void update() 
	{
		int index = 0;

		std::cout << "HealthSystem Update" << std::endl;
		for (Entity &entity : entities)
		{
			for (Component* component : entity.getComponents())
			{
				if (component->getID() == 2)
				{
					
					healthComp = dynamic_cast<HealthComponent*>(component);
					int healthVal = healthComp->getHealth();
					if (healthVal > 0)
					{
						healthVal -=1;
						healthComp->setHealth(healthVal);

						std::cout << "Update health component" << std::endl;

						std::cout << "Health: " << healthComp->getHealth() << std::endl;
					}
					else
					{
						std::cout << "Entity has 0 health" << std::endl;
					}
					index++;
				}
				
			}
		}
		std::cout << "" << std::endl;
	}
};
