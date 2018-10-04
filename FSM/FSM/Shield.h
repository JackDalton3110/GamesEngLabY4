#pragma once

#include "Command.h"
#include <iostream>

class Shield : public Command
{
public:
	virtual void execute() { std::cout << "shield" << std::endl; }
};