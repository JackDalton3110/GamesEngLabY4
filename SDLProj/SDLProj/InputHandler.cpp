#include "InputHandler.h"

InputHandler::InputHandler()
{
	buttonJ_ = new Jump();
	buttonH_ = new Fire();
	buttonU_ = new Crouch();
	buttonK_ = new Melee();
	buttonI_ = new Shield();
	macro = new MacroCommand();

}

InputHandler::~InputHandler()
{

}

void InputHandler::handleInput(SDL_Event & event)
{

	switch (event.type)
	{
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_j:
			buttonJ_->execute();
			macro->add(buttonJ_);
			break;
		case SDLK_h:
			buttonH_->execute();
			macro->add(buttonH_);
			break;
		case SDLK_u:
			buttonU_->execute();
			macro->add(buttonU_);
			break;
		case SDLK_k:
			buttonK_->execute();
			macro->add(buttonK_);
			break;
		case SDLK_i:
			buttonI_->execute();
			macro->add(buttonI_);
			break;
		case SDLK_z:
			macro->execute();
			break;


		}

	}

}