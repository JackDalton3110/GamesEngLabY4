#pragma once

#include "Command.h"
#include <iostream>

class Crouch : public Command
{
public:
	virtual void execute() { std::cout << "crouch" << std::endl; }

	virtual void undo() { std::cout << "Undo crouch" << std::endl; }

	virtual void redo() { std::cout << "Redo crouch" << std::endl; }
};