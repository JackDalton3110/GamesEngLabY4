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

	void handleInput(SDL_Event & event);



private:
	Command * buttonJ_;
	Command * buttonH_;
	Command * buttonU_;
	Command * buttonK_;
	Command * buttonI_;
	MacroCommand * macro;
	Animation fsm;

};