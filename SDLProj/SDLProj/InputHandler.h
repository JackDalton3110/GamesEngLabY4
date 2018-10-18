#pragma once

#include "Command.h"
#include "Fire.h"
#include "Jump.h"
#include "Crouch.h"
#include "Melee.h"
#include "MacroCommand.h"
#include "Shield.h"

#include <SDL.h>

class InputHandler
{
public:
	InputHandler();
	~InputHandler();

	void handleInput(SDL_Event & event);

private:
	Command * buttonT_;
	Command * buttonY_;
	Command * buttonU_;
	Command * buttonI_;
	Command * buttonO_;
	MacroCommand * macro;

};