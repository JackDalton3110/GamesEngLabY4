#pragma once
#include "State.h"
#include "Idle.h"
#include <iostream>

class Jumping : public State
{
public:
	Jumping() {};
	~Jumping() {};
	void idle(Animation* a)
	{
		std::cout << "Going from Jumping to Idling" << std::endl;
		a->setCurrent(new Idle());
		delete this;
	}
};