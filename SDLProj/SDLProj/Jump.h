#pragma once

#include "Command.h"
#include <iostream>

class Jump : public Command
{
public:
	virtual void execute() { std::cout << "jump" << std::endl; }
};