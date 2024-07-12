#pragma once
#include <raylib.h>
#include <cstdint>


class Map {
private:
	typedef struct Block {
		Texture2D Texture;
		Rectangle Collision;
		Vector2 Position;
	} Block;

	Block *_Block;

public:
	Map(uint16_t SizeOfMap, int32_t seed);
	~Map();

	void Draw();
	Rectangle GetBlockColission();

};