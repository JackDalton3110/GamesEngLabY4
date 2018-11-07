#include "Entity.h"
#include "HealthComponent.h"
#include "PositionComponent.h"
#include "PositionSystem.h"
#include "HealthSystem.h"
#include "Component.h"
#include "AISystem.h"
#include "RenderSystem.h"
#include "ControlSystem.h"

int main(int argc, char* argv[])
{
	Entity player;
	player.addComponent(new HealthComponent()); player.addComponent(new PositionComponent()); 
	player.addComponent(new ControlComponent());

	Entity enemy;
	enemy.addComponent(new HealthComponent()); enemy.addComponent(new PositionComponent());

	Entity dog;
	dog.addComponent(new HealthComponent()); dog.addComponent(new PositionComponent());

	Entity cat; 
	cat.addComponent(new HealthComponent()); cat.addComponent(new PositionComponent());

	HealthSystem hs; PositionSystem ps; RenderSystem rs; AISystem ai; ControlSystem cs;
	hs.addEntity(player); 
	hs.addEntity(enemy);
	hs.addEntity(dog);
	hs.addEntity(cat);
	
	ps.addEntity(player);
	ps.addEntity(enemy);
	ps.addEntity(dog);
	ps.addEntity(cat);

	rs.addEntity(player);
	rs.addEntity(enemy);
	rs.addEntity(dog);
	rs.addEntity(cat);

	ai.addEntity(enemy);
	ai.addEntity(dog);
	ai.addEntity(cat);

	cs.addEntity(player);

	SDL_Event e;

	while (true) {
		hs.update(); ps.update();
		rs.update(); ai.update();
		cs.update(e);
	}
	return 0;
}