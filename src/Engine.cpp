#include "../Engine.hpp"
#include <raylib.h>

Engine::Engine(int WindowWidth, int WindowHeight) {
	InitWindow(WindowWidth,WindowHeight, "BulletHell");
	Engine::Camera.zoom = 1;
	Engine::Camera.target = (Vector2){static_cast<float>(WindowWidth / 2.0),static_cast<float>(WindowHeight / 2.0)};
	Engine::Camera.offset = (Vector2){static_cast<float>(WindowWidth / 2.0),static_cast<float>(WindowHeight / 2.0)};
	Engine::Camera.rotation = 0;
}

Engine::~Engine() {
	CloseWindow();
}

//game logic
void Engine::Update() {

}

//game Render
void Engine::Render() {
	BeginDrawing();
	BeginMode2D(Engine::Camera);

	DrawRectangle(200, 200, 200, 200, WHITE);

	EndMode2D();
	EndDrawing();
}