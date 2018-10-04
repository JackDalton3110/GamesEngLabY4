#include "Animation.h"
#include "Idle.h"

Animation::Animation()
{
	current = new Idle();
}

void Animation::idle()
{
	current->idle(this);
}

void Animation::jump()
{
	current->jumping(this);
}

void Animation::climb()
{
	current->climbing(this);
}

void Animation::setCurrent(State* s)
{
		current = s;
}