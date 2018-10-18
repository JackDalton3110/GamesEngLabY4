#include "InputHandler.h"

InputHandler::InputHandler()
{
	fsm = new Animation();
	m_current = IDLE;
}

InputHandler::~InputHandler()
{

}
void InputHandler::setCurrent(Action a) {
	m_current = a;
}

InputHandler::Action InputHandler::getCurrent() {
	return m_current;
}



void InputHandler::handleInput(SDL_Event & event)
{

	switch (event.type)
	{
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_1:
			fsm->jump();
			if (getCurrent() == IDLE)
			setCurrent(JUMP);
			break;
		case SDLK_2:
			fsm->climb();
			if (getCurrent() == IDLE)
			setCurrent(CLIMB);
			break;
		case SDLK_3:
			fsm->idle();
			setCurrent(IDLE);
			break;
	
		}

	}
	
}