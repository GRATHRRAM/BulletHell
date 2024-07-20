#include <raylib.h>
#include "Engine.hpp"

int main() {
	Engine game(1280,720);
	Map map(2000, 20, 69);

	while(!WindowShouldClose()) {
		game.UpdateEvent();
		game.UpdatePhysics(&map);
		game.UpdateRender(&map);
	}

	return 0;
}
