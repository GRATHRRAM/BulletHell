#include <raylib.h>
#include "Engine.hpp"

int main() {
	Engine game(1280,720);
	Map map(3000, 20, 200);
	Player Player1((Vector2){20.f, -1000.f},1);

	while(!WindowShouldClose()) {
		float delta = GetFrameTime();
		game.UpdateEvent(delta,&Player1);
		game.UpdatePhysics(delta,&Player1);
		game.UpdateCollision(&Player1,&map);
		game.UpdateRender(&map,&Player1);
	}

	return 0;
}
