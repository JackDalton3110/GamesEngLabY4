#include "RenderSystem.h"

RenderSystem::RenderSystem() {

}

void RenderSystem::addEntity(Entity e)
{
	m_entities.push_back(e);
}

void RenderSystem::update()
{
	int index = 0;

	std::cout << "Render System update" << std::endl;
	for (Entity entity : m_entities)
	{
		for (Component *component : entity.getComponents())
		{
			if (component->getID() == 1)
			{
				std::cout << "Checking position component " << index << std::endl;
				
			}
		}
		std::cout << "Drawing entity " << index << std::endl;
		index++;
	}
	std::cout << " " << std::endl;
	std::cout << " " << std::endl;

}