#pragma once

#include "Command.h"
#include <iostream>

class Fire : public Command
{
public:
	virtual void execute() { std::cout << "fire" << std::endl; }
};