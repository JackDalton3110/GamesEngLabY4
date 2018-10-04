#pragma once
#include <iostream>
#include "DrawAPI.h""

//Refinment and Implentation

class Character {
public:
	virtual void Draw() = 0;
};

class Player : public Character {
public:
	Player(DrawAPI* api) {
		this->api = api;
	}
	void Draw() {
		api->Draw();//implementation
	}
private:
	DrawAPI * api; 
};