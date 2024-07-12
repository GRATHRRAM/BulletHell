#include "../Engine.hpp"
#include <raylib.h>

Engine::Engine(int WindowWidth, int WindowHeight) {
	InitWindow(WindowWidth,WindowHeight, "BulletHell");
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
	DrawLine(0, 0, 255, 255, WHITE);
	EndDrawing();
}