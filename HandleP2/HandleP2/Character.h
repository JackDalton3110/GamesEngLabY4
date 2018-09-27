#pragma once
#include <iostream>
#include "DrawAPI.h""

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
		api->Draw();
	}
private:
	DrawAPI * api;
};