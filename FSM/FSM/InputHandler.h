#pragma once

#include "Command.h"
#include "Fire.h"
#include "Jump.h"
#include "Crouch.h"
#include "Melee.h"
#include "MacroCommand.h"
#include "Shield.h"
#include "Animation.h"

#include <SDL.h>
#include <iostream>

class InputHandler
{
public:
	InputHandler();
	~InputHandler();


	enum Action
	{
		IDLE,
		JUMP,
		CLIMB
	};
	void handleInput(SDL_Event & event, SDL_Rect &endrect);
	void setCurrent(Action);
	Action getCurrent();
private:


	Animation * fsm;
	Action m_current;

};