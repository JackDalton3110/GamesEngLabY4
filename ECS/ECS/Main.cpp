#include "Entity.h"
#include "HealthComponent.h"
#include "PositionComponent.h"
#include "System.h"

int main(void*)
{
	Entity player;
	HealthComponent hc; PositionComponent pc;
	player.addComponent(hc); player.addComponent(pc);

	HealthSystem hs; PositionSystem ps;
	hs.addEntity(player); ps.addEntity(player);

	while (true) {
		hs.update(); ps.update();
	}
	return 0;
}