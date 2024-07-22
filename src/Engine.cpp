#include "../Engine.hpp"
#include <raylib.h>
#include <raymath.h>

Engine::Engine(int WindowWidth, int WindowHeight,Player *Player1,Player *Player2,Map *map) {
	InitWindow(WindowWidth,WindowHeight, "BulletHell");
	Engine::Camera.zoom = 0.1;
	Engine::Camera.target = (Vector2){static_cast<float>(WindowWidth / 2.0),static_cast<float>(WindowHeight / 2.0)};
	Engine::Camera.offset = (Vector2){static_cast<float>(WindowWidth / 2.0),static_cast<float>(WindowHeight / 2.0)};
	Engine::Camera.rotation = 0;
	SetTargetFPS(60);

	Engine::Player1 = Player1;
	Engine::Player2 = Player2;
	Engine::map     = map;
}

Engine::~Engine() {
	CloseWindow();
}

void Engine::UpdateEvent(float delta) {
	Engine::Player1->UpdateEvent(delta);
	Engine::Player2->UpdateEvent(delta);
}

void Engine::UpdatePhysics(float delta) {
	Engine::Player1->UpdatePhysics(delta);
	Engine::Player2->UpdatePhysics(delta);
}

void Engine::UpdateCollision() {
	Engine::Player1->CheckCollision(Engine::map,Engine::Player2);
	Engine::Player2->CheckCollision(Engine::map,Engine::Player1);
}

void Engine::UpdateRender() {
	BeginDrawing();
	ClearBackground(BLACK);
	BeginMode2D(Engine::Camera);

	Engine::map->Draw();
	Engine::Player1->Draw();
	Engine::Player2->Draw();

	EndMode2D();
	Engine::UpdateGui();
	EndDrawing();
}

void Engine::UpdateCamera(float zoom) {
	float _zoom = abs(Vector2Distance(
		(Vector2){Player1->Collision.x,Player1->Collision.y},
		(Vector2){Player2->Collision.x,Player2->Collision.y}))
		* (zoom * 0.005);
	Engine::Camera.zoom = Clamp(zoom / _zoom,0.09,0.3);

	Engine::Camera.target.x = (Engine::Player1->Collision.x + Engine::Player2->Collision.x) / 2;
	Engine::Camera.target.y = (Engine::Player1->Collision.y + Engine::Player2->Collision.y) / 2;
}

void Engine::UpdateGui() {
	DrawText(TextFormat("Player1 Points: %i\n\nPlayer2 Points: %i",
	Engine::Player1->Points,Engine::Player2->Points),10,10,25,WHITE);
}
