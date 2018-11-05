#pragma once
#include <iostream>
#include "SDL.h"

class Animation 
{
	class State* current;
public:
	Animation();

	void setCurrent(State* s)
	{
		current = s;
	}
	

	void idle(SDL_Rect &endrect);
	void jump(SDL_Rect &endrect);
	void climb(SDL_Rect &endrect);
};