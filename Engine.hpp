#pragma once
#include <raylib.h>
#include "Map.hpp"
#include "Player.hpp"

class Engine {
public:
	Engine(int WindowWidth, int WindowHeight);
	~Engine();

	void UpdateEvent(float delta, Player *Player1, Player *Player2);
	void UpdatePhysics(float delta,Player *Player1, Player *Player2);
	void UpdateCollision(Player *Player1, Player *Player2, Map *map); 
	void UpdateRender(Map *map,Player *Player1, Player *Player2);
	void UpdateCamera(Player *Player1,Player *Player2, float zoom);
	void UpdateGui(Player *Player1,Player *Player2);
private:
	Camera2D Camera;
};