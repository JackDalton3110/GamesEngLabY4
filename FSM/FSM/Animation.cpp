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
	current->jump(this);
}

void Animation::climb()
{
	current->climb(this);
}