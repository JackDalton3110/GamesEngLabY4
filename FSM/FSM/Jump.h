#pragma once
#include "State.h"
#include "Idle.h"
#include <iostream>

class Jumping : public State
{
public:
	Jumping();
	~Jumping();
	void idle(Animation* a);
};