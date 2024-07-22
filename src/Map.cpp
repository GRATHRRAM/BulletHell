#include "../Map.hpp"
#include <raylib.h>

Map::Map(uint16_t SizeOfMap, uint16_t CoutOfOBJ, uint32_t seed) {
    Map::New(SizeOfMap, CoutOfOBJ, seed);
}

Map::~Map() {
    if(Map::_Block != nullptr) delete[] Map::_Block;
}

void Map::Draw() {
    for(uint16_t i = 0; i < Map::_BlockSize; ++i) {
        //narazie nie wczytuje ani nie rysuje textur bo nie trzeba puki co
        DrawRectangleRec(Map::_Block[i].Collision, VIOLET);
    }
}

Rectangle Map::GetBlockColission(uint16_t i) {
    return Map::_Block[i].Collision;
}

uint16_t Map::GetBlockArrSize() {
    return Map::_BlockSize;
}

bool Map::New(uint16_t SizeOfMap, uint16_t CoutOfOBJ, uint32_t seed) {
    if(Map::_Block != nullptr) delete[] Map::_Block;

    Map::_Block = new Map::Block[CoutOfOBJ];

    if(Map::_Block != nullptr) {
        SetRandomSeed(seed);

        for(uint16_t i = 0; i < CoutOfOBJ; ++i) {
            Map::_Block[i].TextureID = 0;

            Map::_Block[i].Collision = (Rectangle){
                static_cast<float>(GetRandomValue(SizeOfMap*-1,SizeOfMap)),
                static_cast<float>(GetRandomValue(SizeOfMap*-1,SizeOfMap)),
                static_cast<float>(GetRandomValue(50,1000)),
                static_cast<float>(GetRandomValue(50,350))
            };
        }

        Map::_BlockSize = CoutOfOBJ;
        Map::SizeOfMap = SizeOfMap;
        return false;
    }
    return true;
}
    