// This is the implementation file for the player.

#include "player.h"

#include <SDL2/SDL.h>

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
        x_accel = 2;
    }

    Entity_Fall::update(map);
}
