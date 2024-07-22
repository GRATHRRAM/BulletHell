#include <raylib.h>
#include "../Player.hpp"

Player::Player(Map *map, uint8_t WitchPlayer) {
    if(WitchPlayer == 1) Player::Collision.x = -1000.f;
    else                 Player::Collision.x =  1000.f;

    Player::Collision.y = (map->SizeOfMap * -1) - 200;
    Player::WitchPlayer = WitchPlayer;
}

void Player::Draw() {
    if(Player::WitchPlayer == 1) DrawRectangleRec(Player::Collision, GREEN);
    else DrawRectangleRec(Player::Collision, RED);
}

void Player::UpdateEvent(float Delta) {
    if(WitchPlayer == 1) {
        if(IsKeyPressed(KEY_W) && Player::OnGround) Player::Velocity.y = -20;
        if(IsKeyPressed(KEY_S) && Player::OnGround) Player::Velocity.y = 20;
        if(IsKeyDown(KEY_A)) Player::Velocity.x -= Player::speed * Delta;
        if(IsKeyDown(KEY_D)) Player::Velocity.x += Player::speed * Delta;
    }
    else {//witchPlayer == 2
        if(IsKeyPressed(KEY_UP) && Player::OnGround)    Player::Velocity.y = -20;
        if(IsKeyPressed(KEY_DOWN) && Player::OnGround) Player::Velocity.y = 20;
        if(IsKeyDown(KEY_LEFT))  Player::Velocity.x -= Player::speed * Delta;
        if(IsKeyDown(KEY_RIGHT)) Player::Velocity.x += Player::speed * Delta;
    }
    Player::Collision.x += Player::Velocity.x;
    Player::Collision.y += Player::Velocity.y;
}

void Player::UpdatePhysics(float Delta) {
    if(!Player::OnGround) {
        Player::Velocity.y += Player::Gravity * Delta;
    } else {
        Player::Velocity.y = 0;
    }

    Player::Velocity.x *= Player::Friction;//fricton

    if(Player::Velocity.x > 100) Player::Velocity.x = 100;
    if(Player::Velocity.x < -100) Player::Velocity.x = -100;
}

void Player::CheckCollision(Map *map,Player *Player2) {
    if(Player::Collision.y > map->SizeOfMap + 1000) Player::Die(map,Player2);

    for(uint16_t i = 0; i < map->GetBlockArrSize(); ++i) {
        if ( map->GetBlockColission(i).y <= Player::Collision.y + Player::Collision.height &&
             Player::Collision.y <= map->GetBlockColission(i).y + map->GetBlockColission(i).height &&
            Player::Collision.x + Player::Collision.width >=  map->GetBlockColission(i).x &&
            Player::Collision.x <= map->GetBlockColission(i).x + map->GetBlockColission(i).width) {
            Player::OnGround = true;
            return;
        }
    }
    Player::OnGround = false;
}

void Player::Die(Map *map,Player *Player2) {
    if(Player::WitchPlayer == 1) Player::Collision.x = -1000.f;
    else                         Player::Collision.x =  1000.f;
    Player::Collision.y = (map->SizeOfMap * -1) - 200;
    Player::Velocity = {0,0};

    if(Player2->WitchPlayer == 1) Player2->Collision.x = -1000.f;
    else                          Player2->Collision.x =  1000.f;
    Player2->Collision.y = (map->SizeOfMap * -1) - 200;
    Player2->Velocity = {0,0};

    Player2->Points++;
    Player::isded = true;
}