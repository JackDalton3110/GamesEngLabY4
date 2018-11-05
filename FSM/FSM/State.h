#pragma once
#include <iostream>
#include "Animation.h"
#include "SDL.h"

class State {
public:
	virtual void idle(Animation* a, SDL_Rect &endrect)
	{
		std::cout << "State::Idling" << std::endl;
	}

	virtual void jumping(Animation* a, SDL_Rect &endrect)
	{
		std::cout << "State::Jumping" << std::endl;
	}

	virtual void climbing(Animation* a, SDL_Rect &endrect)
	{
		std::cout << "State::Climbing" << std::endl;
	}
};