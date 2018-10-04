#pragma once
#include <iostream>

class Animation 
{
	class State* current;
public:
	Animation();

	void setCurrent(State* s);
	

	void idle();
	void jump();
	void climb();
};