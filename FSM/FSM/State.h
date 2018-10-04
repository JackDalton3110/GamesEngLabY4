#pragma once
#include <iostream>
#include "Animation.h"

class State {
public:
	virtual void idle(Animation* a)
	{
		std::cout << "State::Idling" << std::endl;
	}

	virtual void jump(Animation* a)
	{
		std::cout << "State::Jumping" << std::endl;
	}

	virtual void climb(Animation* a)
	{
		std::cout << "State::Climbing" << std::endl;
	}
};