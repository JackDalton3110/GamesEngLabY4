#pragma once
#include <iostream>

///Abstaraction / Interface and implementation

class DrawAPI {

public:

	virtual void Draw() = 0;

};

class DrawImpl : public DrawAPI {

public:

	void Draw() {
		std::cout << "Draw Impl" << std::endl;
	}
};