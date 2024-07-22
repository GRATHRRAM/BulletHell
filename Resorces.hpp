#pragma once
#include <raylib.h>
#include <iostream>

class Resorces {
private:
    Texture brick; //id 1
    Texture Pistol;//id 2
public:
    Resorces();
};

Resorces::Resorces() {
    std::cout << "STARTING LOADING TEXTURES" << std::endl;

    Resorces::brick = LoadTexture("./txt/brick.png");
    if(!brick.id <= 0) std::cout << "./txt/brick.png LOADED" << std::endl;
    else std::cout << "./txt/brick.png NOT LOADED!!!" << std::endl;

    Resorces::Pistol = LoadTexture("./txt/pistol.png");
    if(!Pistol.id <= 0) std::cout << "./txt/pistol.png LOADED" << std::endl;
    else std::cout << "./txt/pistol.png NOT LOADED!!!" << std::endl;

    std::cout << "TEXTURES LOADING DONE!" << std::endl;
}