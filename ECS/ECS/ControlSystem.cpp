#include "ControlSystem.h"

ControlSystem::ControlSystem()
{

}

void ControlSystem::input(SDL_Event &e)
{
	for (Entity &entity : entities)
	{
		for (Component *comp : entity.getComponents())
		{
			if (comp->getID() == 3)
			{
				controlComp = dynamic_cast<ControlComponent*>(comp);
				switch (e.type)
				{
				case SDL_KEYDOWN:
					switch (e.key.keysym.sym)
					{
					default:
						controlComp->setDir(controlComp->Idle);
						break;
					case SDLK_w:
						controlComp->setDir(controlComp->MoveUp);
						break;
					case SDLK_a:
						controlComp->setDir(controlComp->MoveLeft);
						break;
					case SDLK_s:
						controlComp->setDir(controlComp->MoveDown);
						break;
					case SDLK_d:
						controlComp->setDir(controlComp->MoveRight);
						break;
					}

				}
			}
		}
	}
}

void ControlSystem::update(SDL_Event &e)
{
	for (Entity &entity : entities)
	{
		for (Component* component : entity.getComponents())
		{
			if (component->getID() == 1)
			{
				pos = dynamic_cast<PositionComponent*>(component);
			}
			else if (component->getID() == 3) {
				controlComp = dynamic_cast<ControlComponent*>(component);
			}
		}
	}

	x = pos->getPosX();
	y = pos->getPosY();

	input(e);
	if (controlComp->getDir() == controlComp->MoveUp)
	{
		y -= speed;
	}
	else if (controlComp->getDir() == controlComp->MoveDown)
	{
		y += speed;
	}

	if (controlComp->getDir() == controlComp->MoveRight)
	{
		x += speed;
	}
	else if (controlComp->getDir() == controlComp->MoveLeft)
	{
		x -= speed;
	}
	pos->setPos(x, y);
}