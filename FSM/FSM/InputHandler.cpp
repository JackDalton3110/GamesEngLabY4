#include "InputHandler.h"

InputHandler::InputHandler()
{

	//buttonJ_ = a->jump();
	/*buttonH_ = new Fire();
	buttonU_ = new Crouch();
	buttonK_ = new Melee();
	buttonI_ = new Shield();*/
	/*macro = new MacroCommand();*/

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
		case SDLK_w:
			fsm.jump();
			break;
		case SDLK_a:
			fsm.climb();
			break;
		case SDLK_s:
			fsm.idle();
			break;
		//case SDLK_k:
		//	//buttonK_->execute();
		//	//macro->add(buttonK_);
		//	break;
		//case SDLK_i:
		//	//buttonI_->execute();
		//	//macro->add(buttonI_);
		//	break;
		//case SDLK_z:
		//	macro->execute();
		//	break;


		}

	}

}