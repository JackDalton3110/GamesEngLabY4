#include "Entity.h"
#include "HealthComponent.h"
#include "PositionComponent.h"
#include "PositionSystem.h"
#include "HealthSystem.h"
#include "Component.h"

int main(void*)
{
	Entity player;
	player.addComponent(new HealthComponent()); player.addComponent(new PositionComponent());

	Entity enemy;
	enemy.addComponent(new HealthComponent()); enemy.addComponent(new PositionComponent());

	Entity dog;
	dog.addComponent(new HealthComponent()); dog.addComponent(new PositionComponent());

	Entity cat; 
	cat.addComponent(new HealthComponent()); cat.addComponent(new PositionComponent());

	HealthSystem hs; PositionSystem ps;
	hs.addEntity(player); 
	hs.addEntity(enemy);
	hs.addEntity(dog);
	hs.addEntity(cat);
	
	ps.addEntity(player);
	ps.addEntity(enemy);
	ps.addEntity(dog);
	ps.addEntity(cat);

	while (true) {
		hs.update(); ps.update();
	}
	return 0;
}