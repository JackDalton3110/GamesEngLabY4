#include "InputHandler.h"

InputHandler::InputHandler()
{
	buttonT_ = new Jump();
	buttonY_ = new Fire();
	buttonU_ = new Crouch();
	buttonI_ = new Melee();
	buttonO_ = new Shield();
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
		case SDLK_t:
			buttonT_->execute();
			macro->add(buttonT_);
			break;
		case SDLK_y:
			buttonY_->execute();
			macro->add(buttonY_);
			break;
		case SDLK_u:
			buttonU_->execute();
			macro->add(buttonU_);
			break;
		case SDLK_i:
			buttonI_->execute();
			macro->add(buttonI_);
			break;
		case SDLK_o:
			buttonO_->execute();
			macro->add(buttonO_);
			break;
		case SDLK_z:
			macro->execute();
			break;
		case SDLK_1:
			macro->undo();
			break;
		case SDLK_2:
			macro->redo();
			break;


		}

	}

}