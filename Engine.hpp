#pragma once
#include <raylib.h>
#include "Map.hpp"

class Engine {
public:
	Engine(int WindowWidth, int WindowHeight);
	~Engine();

	void UpdateEvent();
	void UpdatePhysics(Map *map);
	void UpdateRender(Map *map);
private:
	Camera2D Camera;
};