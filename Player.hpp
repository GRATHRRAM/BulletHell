#pragma once
#include <raylib.h>
#include <stdint.h>
#include "Map.hpp"


class Player {
public: //add texture later
	Player(Map *map, uint8_t WitchPlayer);

	uint8_t WitchPlayer;
	float speed = 25;
	Vector2 Velocity = {0,0};
	Rectangle Collision = {0,0,100,200};
	float Gravity = 20;
	float Friction = 0.98;
	uint32_t Points = 0;
	bool isded = false;

	void Draw();
	void UpdateEvent(float Delta);
	void UpdatePhysics(float Delta);
	void CheckCollision(Map *map,Player *OtherPlayer);
	void Die(Map *map,Player *Player2);
	private:
	bool OnGround = false;
};