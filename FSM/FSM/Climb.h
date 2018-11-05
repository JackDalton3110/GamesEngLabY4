#pragma once
#include "State.h"
#include "Idle.h"
#include <iostream>

class Climbing : public State
{
public:
	Climbing() {};
	~Climbing() {};
	void idle(Animation* a, SDL_Rect &endrect)
	{
		std::cout << "Going from Climbing to Idling" << std::endl;
		a->setCurrent(new Idle());
		endrect.y = 0;
		delete this;
	}
};