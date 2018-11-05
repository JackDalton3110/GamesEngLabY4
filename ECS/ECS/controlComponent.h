#pragma once
#include <vector>
#include "Component.h"

class ControlComponent : public Component
{
public:
	ControlComponent(){}
	int getID() { return id; }
private:
	int id = 3;
};
