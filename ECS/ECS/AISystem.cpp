#include "AISystem.h"

void AISystem::addEntity(Entity e) 
{ 
	m_entities.push_back(e); 
}

void AISystem::update()
{

	std::cout << "AI System" << std::endl;

	for (Entity &entity : m_entities)
	{
		for (Component *component : entity.getComponents())
		{
			if (component->getID() == 1)
			{
				posComp = dynamic_cast<PositionComponent*>(component);
				x = posComp->getPosX();
				y = posComp->getPosY();

				y -= speed;
				x -= speed;

				BoundaryChecking();
				std::pair<float, float> pos = { x,y };
				posComp->setPos(x, y);

				index++;

				std::cout << "Updating position component" << std::endl;
				std::cout << "AI posx: " << posComp->getPosX() << " AI posy: " << posComp->getPosY() << std::endl;
			}
		}
	}

	std::cout << "" << std::endl;
}

void AISystem::BoundaryChecking() {
	if (x > screenWidth)
	{
		x = 0;
	}
	else if (x < 0)
	{
		x = screenWidth;
	}
	

	if (y > screenHeight)
	{
		y = 0;
	}
	else if (y < 0)
	{
		y = screenHeight;
	}
}