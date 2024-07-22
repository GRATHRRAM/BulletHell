#pragma once
#include <raylib.h>
#include <stdint.h>
#include "Map.hpp"
#include <vector>


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
	bool lastDir = false;//false == left

	typedef struct bullet {
		Vector2 Velocity;
		Vector2 Position;
		Vector2 Size;
	} bullet;
	std::vector<bullet> bullets;

	void Draw();
	void UpdateEvent(float Delta);
	void UpdatePhysics(float Delta);
	void CheckCollision(Map *map,Player *OtherPlayer);
	void Die(Map *map,Player *Player2);
	void Shoot(Vector2 Velocity, Vector2 Size);

	private:
	bool OnGround = false;
};