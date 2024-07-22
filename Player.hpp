#pragma once
#include <raylib.h>
#include <stdint.h>
#include "Map.hpp"


class Player {
public: //add texture later
	Player(Vector2 SpawnPosition, uint8_t WitchPlayer);

	uint8_t WitchPlayer;
	float speed = 25;
	Vector2 Velocity = {0,0};
	Rectangle Collision = {0,0,100,200};
	float Gravity = 20;
	float Friction = 0.98;
	uint32_t Points = 0;

	void Draw();
	void UpdateEvent(float Delta);
	void UpdatePhysics(float Delta);
	void CheckCollision(Map *map);
	private:
	bool OnGround = false;
};