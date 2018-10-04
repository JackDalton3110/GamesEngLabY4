#pragma once
#include "State.h"
#include <iostream>

class Idle : public State
{
public:
	Idle();
	~Idle();
	void jumping(Animation* a);
	void climbing(Animation* a);
};