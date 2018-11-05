#pragma once
#include "State.h"
#include <iostream>

class Idle : public State
{
public:
	Idle() {};
	~Idle() {};

	void jumping(Animation* a, SDL_Rect &endrect);
	void climbing(Animation* a, SDL_Rect &endrect);
};