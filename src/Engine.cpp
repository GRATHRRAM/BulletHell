#include "../Engine.hpp"
#include <raylib.h>

Engine::Engine(int WindowWidth, int WindowHeight) {
	InitWindow(WindowWidth,WindowHeight, "BulletHell");
	Engine::Camera.zoom = 0.1;
	Engine::Camera.target = (Vector2){static_cast<float>(WindowWidth / 2.0),static_cast<float>(WindowHeight / 2.0)};
	Engine::Camera.offset = (Vector2){static_cast<float>(WindowWidth / 2.0),static_cast<float>(WindowHeight / 2.0)};
	Engine::Camera.rotation = 0;
	SetTargetFPS(60);
}

Engine::~Engine() {
	CloseWindow();
}

void Engine::UpdateEvent(float delta, Player *Player1) {
	Player1->UpdateEvent(delta);
}

void Engine::UpdatePhysics(float delta, Player *Player1) {
	Player1->UpdatePhysics(delta);
}

void Engine::UpdateCollision(Player *Player1, Map *map) {
	Player1->CheckCollision(map);
}

void Engine::UpdateRender(Map *map,Player *Player1) {
	BeginDrawing();
	ClearBackground(BLACK);
	BeginMode2D(Engine::Camera);

	map->Draw();
	Player1->Draw();

	EndMode2D();
	EndDrawing();
}