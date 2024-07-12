#include <raylib.h>
#include "Engine.hpp"

int main() {
	Engine game(1280,720);

	while(!WindowShouldClose()) {
		game.Update();
		game.Render();
	}

	return 0;
}
