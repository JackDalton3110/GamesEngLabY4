#pragma once
#include "Entity.h"
#include <iostream>
#include <vector>
#include "SDL.h"

class ControlSystem
{

public:
	ControlSystem();
	void addEntity(Entity e) { entities.push_back(e); }
	void update();
	void input(SDL_Event &e);

private:
	std::vector<Entity> entities;
	PositionComponent* pos;
	ControlComponent* controlComp;

	float x = 0;
	float y = 0;
	float speed = 2;
	int windowWidth = 1000;
	int windowHeight = 1000;
	int index = 0;
};