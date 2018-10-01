#pragma once

#include "Command.h"
#include <iostream>

class Melee : public Command
{
public:
	virtual void execute() { std::cout << "mellee" << std::endl; }
};