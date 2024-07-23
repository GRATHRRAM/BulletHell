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
    
    for(uint32_t i = 0; i < bullets.size(); ++i) {
        DrawRectangleV(bullets.at(i).Position, bullets.at(i).Size, YELLOW);
    }
}

void Player::UpdateEvent(float Delta) {
    if(WitchPlayer == 1) {
        if(IsKeyPressed(KEY_W) && Player::OnGround) Player::Velocity.y = -20;
        if(IsKeyPressed(KEY_S) && Player::OnGround) Player::Velocity.y = 20;
        if(IsKeyDown(KEY_A)) {Player::Velocity.x -= Player::speed * Delta;Player::lastDir = false;}
        if(IsKeyDown(KEY_D)) {Player::Velocity.x += Player::speed * Delta;Player::lastDir = true;}
        if(IsKeyPressed(KEY_E) && Player::lastDir) Shoot((Vector2){70,0},(Vector2){40,40});
        if(IsKeyPressed(KEY_E) && !Player::lastDir) Shoot((Vector2){-70,0},(Vector2){40,40});
    }
    else {//witchPlayer == 2
        if(IsKeyPressed(KEY_UP) && Player::OnGround)    Player::Velocity.y = -20;
        if(IsKeyPressed(KEY_DOWN) && Player::OnGround) Player::Velocity.y = 20;
        if(IsKeyDown(KEY_LEFT))  {Player::Velocity.x -= Player::speed * Delta; Player::lastDir = false;}
        if(IsKeyDown(KEY_RIGHT)) {Player::Velocity.x += Player::speed * Delta; Player::lastDir = true;}
        if(IsKeyPressed(KEY_SPACE) && Player::lastDir) Shoot((Vector2){70,0},(Vector2){40,40});
        if(IsKeyPressed(KEY_SPACE) && !Player::lastDir) Shoot((Vector2){-70,0},(Vector2){40,40});
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

    for(uint32_t i = 0; i < bullets.size(); ++i) {
        bullets.at(i).Position.x += bullets.at(i).Velocity.x;
        bullets.at(i).Position.x += bullets.at(i).Velocity.y;
    }
}

void Player::CheckCollision(Map *map,Player *Player2) {
    if(Player::Collision.y > map->SizeOfMap + 1000) Player::Die(map,Player2);

    for(uint32_t i = 0; i < bullets.size(); ++i) {
        for(uint16_t im = 0; im < map->GetBlockArrSize(); ++im) {
            if (map->GetBlockColission(im).y <= bullets.at(i).Position.y + bullets.at(i).Size.y &&
                bullets.at(i).Position.y  <= map->GetBlockColission(im).y + map->GetBlockColission(im).height &&
                bullets.at(i).Position.x + bullets.at(i).Size.x >=  map->GetBlockColission(im).x &&
                bullets.at(i).Position.x  <= map->GetBlockColission(im).x + map->GetBlockColission(im).width) {

                bullets.erase(bullets.begin() + i);
                break;
            }
            if (bullets.at(i).Position.x > map->SizeOfMap + 1000 ||
                bullets.at(i).Position.x < (map->SizeOfMap * -1) - 1000 ||
                bullets.at(i).Position.y > map->SizeOfMap + 1000 ||
                bullets.at(i).Position.y < (map->SizeOfMap * -1) - 1000) {

                bullets.erase(bullets.begin() + i);
                break;
            }
        }
    }

    for(uint32_t i = 0; i < Player2->bullets.size(); ++i) {

        if (Player2->bullets.at(i).Position.y <= Player::Collision.y + Player::Collision.height &&
            Player::Collision.y <= Player2->bullets.at(i).Position.y  + Player2->bullets.at(i).Size.y  &&
            Player::Collision.x + Player::Collision.width >=  Player2->bullets.at(i).Position.x  &&
            Player::Collision.x <= Player2->bullets.at(i).Position.x  + Player2->bullets.at(i).Size.x ) {
            
            Player::Velocity.x += Player2->bullets.at(i).Velocity.x;
            Player::Velocity.y += Player2->bullets.at(i).Velocity.y;
            Player2->bullets.erase(Player2->bullets.begin() + i);
        }
    }

    for(uint16_t i = 0; i < map->GetBlockArrSize(); ++i) {
        if (map->GetBlockColission(i).y <= Player::Collision.y + Player::Collision.height &&
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
    Player::bullets.clear();
}

void Player::Shoot(Vector2 Velocity, Vector2 Size) {
    Player::bullets.push_back((bullet){Velocity,(Vector2){Player::Collision.x,Player::Collision.y + 50},Size});
}