#include <raylib.h>
#include "Engine.hpp"
#include <time.h>
#include <cstdlib>

int main() {
	srand(time(nullptr));
	SetRandomSeed(rand() % 2147483647);
	Map map(7000,50, GetRandomValue(0,2147483647));
	Player Player1(&map,1);
	Player Player2(&map,2);

	Engine game(1280,720,&Player1,&Player2,&map);

	while(!WindowShouldClose()) {
		float delta = GetFrameTime();
		game.UpdatePhysics(delta);//UpdatePhysics needs to be before event!!! jump will not work
		game.UpdateEvent(delta);
		game.UpdateCollision();
		game.UpdateCamera(1);
		game.UpdateRender();
		if(Player1.isded || Player2.isded) {
			map.New(7000,50,GetRandomValue(0,2147483647));
			Player1.isded = false;
			Player2.isded = false;
		}
	}

	return 0;
}