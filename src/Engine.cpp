#include "../Engine.hpp"
#include <raylib.h>
#include <raymath.h>

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

void Engine::UpdateEvent(float delta, Player *Player1, Player *Player2) {
	Player1->UpdateEvent(delta);
	Player2->UpdateEvent(delta);
}

void Engine::UpdatePhysics(float delta, Player *Player1, Player *Player2) {
	Player1->UpdatePhysics(delta);
	Player2->UpdatePhysics(delta);
}

void Engine::UpdateCollision(Player *Player1, Player *Player2, Map *map) {
	Player1->CheckCollision(map);
	Player2->CheckCollision(map);
}

void Engine::UpdateRender(Map *map,Player *Player1, Player *Player2) {
	BeginDrawing();
	ClearBackground(BLACK);
	Engine::UpdateGui(Player1,Player2);
	BeginMode2D(Engine::Camera);

	map->Draw();
	Player1->Draw();
	Player2->Draw();

	EndMode2D();
	EndDrawing();
}

void Engine::UpdateCamera(Player *Player1, Player *Player2, float zoom) {
	float _zoom = abs(Vector2Distance(
		(Vector2){Player1->Collision.x,Player1->Collision.y},
		(Vector2){Player2->Collision.x,Player2->Collision.y}))
		* (zoom * 0.005);
	Engine::Camera.zoom = Clamp(zoom / _zoom,0.1,0.3);

	Engine::Camera.target.x = (Player1->Collision.x + Player2->Collision.x) / 2;
	Engine::Camera.target.y = (Player1->Collision.y + Player2->Collision.y) / 2;
}

void Engine::UpdateGui(Player *Player1,Player *Player2) {
	DrawText(TextFormat("Player1 Points: %i\n\nPlayer2 Points: %i",
	Player1->Points,Player2->Points),10,10,25,WHITE);
}
