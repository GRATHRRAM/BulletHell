#pragma once
#include <raylib.h>

class Player {
public: //add texture later
	Player();
	~Player();

	Vector2 Position;
	Vector2 Velocity;
	Rectangle rect;  
	Rectangle Collision;

	void Draw();
	void UpdateEvent();
	void CheckCollision();
};