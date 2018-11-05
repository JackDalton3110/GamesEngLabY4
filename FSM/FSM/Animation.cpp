#include "Animation.h"
#include "Idle.h"

Animation::Animation()
{
	current = new Idle();
}

void Animation::idle(SDL_Rect &endrect)
{
	current->idle(this, endrect);
}

void Animation::jump(SDL_Rect &endrect)
{
	current->jumping(this, endrect);
}

void Animation::climb(SDL_Rect &endrect)
{
	current->climbing(this, endrect);
}

