#pragma once
#include <raylib.h>

class Engine {
public:
	Engine(int WindowWidth, int WindowHeight);
	~Engine();
	void Update();
	void Render();
private:
	Camera2D Camera;
};