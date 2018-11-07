#pragma once
#include <vector>
#include "Component.h"

class ControlComponent : public Component
{
public:
	ControlComponent(){}
	int getID() { return id; }

	enum Dir {
		Idle,
		MoveUp,
		MoveDown,
		MoveLeft,
		MoveRight
	};

	void setDir(Dir state)
	{
		currentDir = state;
	}

	Dir getDir()
	{
		return currentDir;
	}

private:
	int id = 3;
	Dir currentDir = Idle;
};
