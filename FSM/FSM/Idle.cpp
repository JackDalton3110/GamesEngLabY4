#include"Idle.h"
#include "Jump.h"
#include "Climb.h"


void Idle::jumping(Animation* a, SDL_Rect &endrect)
{
	std::cout << "Jumping" << std::endl;
	a->setCurrent(new Jumping());
	endrect.y = 345;
	delete this;
}

void Idle::climbing(Animation* a, SDL_Rect &endrect)
{
	std::cout << "Climbing" << std::endl;
	a->setCurrent(new Climbing());
	endrect.y = 169;
	delete this;
}