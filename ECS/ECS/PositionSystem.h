#pragma once
#include "Entity.h"
#include <iostream>
#include <vector>


class PositionSystem
{
	std::vector<Entity> entities;

public:
	void addEntity(Entity e) { entities.push_back(e); }
	void update() {
		std::cout << "Position System Update" << std::endl;
		for (Entity &entity : entities)
		{
			for (Component* component : entity.getComponents())
			{
				if (component->getID() == 1)
				{
					float posX = dynamic_cast<PositionComponent*>(component)->getPosX();
					float posY = dynamic_cast<PositionComponent*>(component)->getPosY();

					std::cout << "Checking position component" << std::endl;
					std::cout << "" << std::endl;
				}
			}
		}
	}
};