#pragma once

class Engine {
public:
	Engine(int WindowWidth, int WindowHeight);
	~Engine();
	void Update();
	void Render();
};