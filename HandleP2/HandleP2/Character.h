#pragma once
#include <iostream>
#include "DrawAPI.h""
class Charachter {
public:
	virtual void Draw() = 0;
};
class Player : public Charachter {
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