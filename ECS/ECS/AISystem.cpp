#include "AISystem.h"

void AISystem::addEntity(Entity e)
{
	m_entities.push_back(e);
}

void AISystem::update()
{
	for (Entity &entity : m_entities)
	{
		for (Component *component : entity.getComponents())
		{
			if (component->getID == 1)
			{
				posComp = dynamic_cast<PositionComponent*>(component);
			}
		}
		x = posComp->getPosX();
		y = posComp->getPosY();

		y -= speed;

		BoundaryChecking();
		std::pair<float, float>m_pos = { x,y };
		posComp->setPos(x, y);
	}
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