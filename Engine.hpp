#pragma once
#include <raylib.h>
#include "Map.hpp"
#include "Player.hpp"

class Engine {
public:
	Engine(int WindowWidth, int WindowHeight,Player *Player1,Player *Player2,Map *map);
	~Engine();

	void UpdateEvent(float delta);
	void UpdatePhysics(float delta);
	void UpdateCollision(); 
	void UpdateRender();
	void UpdateCamera(float zoom);
	void UpdateGui();
private:
	Player *Player1;
	Player *Player2;
	Map *map;
	Camera2D Camera;
};