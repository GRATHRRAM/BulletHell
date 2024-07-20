#pragma once
#include <raylib.h>
#include "Map.hpp"
#include "Player.hpp"

class Engine {
public:
	Engine(int WindowWidth, int WindowHeight);
	~Engine();

	void UpdateEvent(float delta, Player *Player1);
	void UpdatePhysics(float delta,Player *Player1);
	void UpdateCollision(Player *Player1, Map *map); 
	void UpdateRender(Map *map,Player *Player1);
private:
	Camera2D Camera;
};