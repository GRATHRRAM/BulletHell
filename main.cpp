#include <raylib.h>
#include "Engine.hpp"
#include <time.h>

int main() {
	Engine game(1280,720);
	Map map(3500,40, 300);
	Player Player1((Vector2){-1000.f, -1000.f},1);
	Player Player2((Vector2){1000.f, -1000.f},2);

	while(!WindowShouldClose()) {
		float delta = GetFrameTime();
		game.UpdatePhysics(delta,&Player1,&Player2);//UpdatePhysics needs to be before event!!! jump will not work
		game.UpdateEvent(delta,&Player1,&Player2);
		game.UpdateCollision(&Player1,&Player2,&map);
		game.UpdateCamera(&Player1,&Player2,1);
		game.UpdateRender(&map,&Player1,&Player2);
	}

	return 0;
}
