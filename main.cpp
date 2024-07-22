#include <raylib.h>
#include "Engine.hpp"
#include <time.h>
#include <cstdlib>

int main() {
	srand(time(nullptr));
	SetRandomSeed(rand() % 2147483647);
	Engine game(1280,720);
	Map map(5000,50, GetRandomValue(0,2147483647));
	Player Player1(&map,1);
	Player Player2(&map,2);

	while(!WindowShouldClose()) {
		float delta = GetFrameTime();
		game.UpdatePhysics(delta,&Player1,&Player2);//UpdatePhysics needs to be before event!!! jump will not work
		game.UpdateEvent(delta,&Player1,&Player2);
		game.UpdateCollision(&Player1,&Player2,&map);
		game.UpdateCamera(&Player1,&Player2,1);
		game.UpdateRender(&map,&Player1,&Player2);
		if(Player1.isded || Player2.isded) {
			map = Map(5000,50,GetRandomValue(0,2147483647));
			Player1.isded = false;
			Player2.isded = false;
		}
	}

	return 0;
}
