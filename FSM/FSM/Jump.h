#pragma once
#include "State.h"
#include "Idle.h"
#include <iostream>

class Jumping : public State
{
public:
	Jumping() {};
	~Jumping() {};
	void idle(Animation* a, SDL_Rect &endrect)
	{
		std::cout << "Going from Jumping to Idling" << std::endl;
		a->setCurrent(new Idle());
		endrect.y = 0;
		delete this;
	}
};