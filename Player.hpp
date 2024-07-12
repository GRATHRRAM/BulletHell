#pragma once
#include <raylib.h>

class Player {
public:
	Player();
	~Player();

	Vector2 Position;
	Vector2 Velocity;
	Rectangle rect;  //replace rect with texture later
	Rectangle Collision;

	void Draw();
	void Update();
	void CheckCollision();
};