#pragma once
#include <raylib.h>
#include <cstdint>

//texturesID
//0 - random color

class Map {
private:
	typedef struct Block {
		uint8_t TextureID;
		Rectangle Collision;
	} Block;

	Block *_Block;
	uint16_t _BlockSize;

public:
	Map(uint16_t SizeOfMap, uint16_t CoutOfOBJ, uint32_t seed);
	~Map();

	void Draw();
	Rectangle GetBlockColission(uint16_t i);//jak i > _BlockSize to segf więc uważaj jak coś tu robisz
	uint16_t GetBlockArrSize();
	uint16_t SizeOfMap;
};