#pragma once
#include <iostream>
#include "Component.h"
#include "HealthComponent.h"
#include "PositionComponent.h"
#include "controlComponent.h"
#include <vector>


class Entity
{
	int id;
public:
	Entity() {};
	void addComponent(Component* c) { components.push_back(c); }
	void removeComponent(Component* c) {}
	std::vector<Component*> getComponents() { return components; }
private:
	std::vector<Component*> components;
	
};