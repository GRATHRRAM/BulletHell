#include <raylib.h>
#include "../Player.hpp"
#include <iostream>

Player::Player(Vector2 SpawnPosition, uint8_t WitchPlayer) {
    Player::Collision.x = SpawnPosition.x;
    Player::Collision.y = SpawnPosition.y;
    Player::WitchPlayer = WitchPlayer;
}

void Player::Draw() {
    DrawRectangleRec(Player::Collision, GRAY);
}

void Player::UpdateEvent(float Delta) {
    if(WitchPlayer == 1) {
        if(IsKeyDown(KEY_W)) Player::Velocity.y = -10;
        if(IsKeyDown(KEY_A)) Player::Velocity.x -= Player::speed * Delta;
        if(IsKeyDown(KEY_D)) Player::Velocity.x += Player::speed * Delta;
    }
    else {//witchPlayer == 2
        if(IsKeyDown(KEY_UP))    Player::Velocity.y = -10;
        if(IsKeyDown(KEY_LEFT))  Player::Velocity.x -= Player::speed * Delta;
        if(IsKeyDown(KEY_RIGHT)) Player::Velocity.x += Player::speed * Delta;
    }
}

void Player::UpdatePhysics(float Delta) {
    if(!Player::OnGround) {
        Player::Velocity.y += Player::Gravity * Delta;
    } else {
        Player::Velocity.y = 0;
    }

    Player::Velocity.x *= 0.99;//fricton
    //if(Player::Velocity.x < 0.0001 || Player::Velocity.x > -0.0001) Player::Velocity.x = 0;

    Player::Collision.x += Player::Velocity.x;
    Player::Collision.y += Player::Velocity.y;
}

void Player::CheckCollision(Map *map) {
    //r1x + r1w >= r2x &&     // r1 right edge past r2 left
    //r1x <= r2x + r2w && 
    for(uint16_t i = 0; i < map->GetBlockArrSize(); ++i) {
        if ( map->GetBlockColission(i).y <= Player::Collision.y + Player::Collision.height &&
            Player::Collision.x + Player::Collision.width >=  map->GetBlockColission(i).x &&
            Player::Collision.x <= map->GetBlockColission(i).x + map->GetBlockColission(i).width) {
            Player::OnGround = true;
            return;
        }
    }
    Player::OnGround = false;
}