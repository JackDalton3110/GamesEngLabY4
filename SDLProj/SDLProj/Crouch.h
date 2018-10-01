#pragma once

#include "Command.h"
#include <iostream>

class Crouch : public Command
{
public:
	virtual void execute() { std::cout << "crouch" << std::endl; }
};