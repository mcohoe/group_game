// This is the implementation file for the player.

#include "player.h"

#include <SDL2/SDL.h>
#include <algorithm>

const int Player::FRICTION;

Player::Player(int x, int y, Graphics* graphics) : Entity_Fall(x, y)
{
    if (graphics != NULL) {
        sprite = Sprite("Graphics/GloriousPlayer.png", graphics);
    }
    hitbox.set_wh(32, 64);
}

void Player::update(Map& map, const Uint8* keys)
{
    if (keys[SDL_SCANCODE_RIGHT]) {
        x_accel = 5;
    }
    else if (keys[SDL_SCANCODE_LEFT]) {
        x_accel = -5;
    }
    else {
        if (x_vel > 0) {
            if (-FRICTION > -x_vel) x_accel = -FRICTION;
            else x_accel = -x_vel;
        }
        else if (x_vel < 0) {
            if (FRICTION < -x_vel) x_accel = FRICTION;
            else x_accel = -x_vel;
        }
        else x_accel = 0;
    }
    if (on_ground) {
        if (keys[SDL_SCANCODE_UP]) {
            y_accel = -64;
        }
    }

    Entity_Fall::update(map);
}

