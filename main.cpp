#include <raylib.h>
#include "Engine.hpp"

int main() {
	Engine game(1280,720);
	Map map(3000,30, 200);
	Player Player1((Vector2){0.f, -1000.f},1);
	Player Player2((Vector2){100.f, -1000.f},2);

	while(!WindowShouldClose()) {
		float delta = GetFrameTime();
		game.UpdatePhysics(delta,&Player1,&Player2);//UpdatePhysics needs to be before event!!! jump will not work
		game.UpdateEvent(delta,&Player1,&Player2);
		game.UpdateCollision(&Player1,&Player2,&map);
		game.UpdateRender(&map,&Player1,&Player2);
	}

	return 0;
}
