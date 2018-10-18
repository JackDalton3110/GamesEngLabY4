#pragma once

#include "Command.h"
#include <iostream>

class Melee : public Command
{
public:
	virtual void execute() { std::cout << "melee" << std::endl; }

	virtual void undo() { std::cout << "Undo melee" << std::endl; }

	virtual void redo() { std::cout << "Redo melee" << std::endl; }
};