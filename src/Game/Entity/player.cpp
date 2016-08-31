// This is the implementation file for the player.

#include "player.h"

Player::Player(int x, int y, Graphics* graphics) : Entity_Fall(x, y)
{
    if (graphics != NULL) {
        sprite = Sprite("Graphics/GloriousPlayer.png", graphics);
    }
}

void Player::update(Map& map, Uint8* keys)
{
    // Do stuff with input
    Entity_Fall::update(map);
}
