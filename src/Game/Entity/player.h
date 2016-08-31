// This is the header file for the player.

#ifndef PLAYER_H
#define PLAYER_H

#include "entity_fall.h"
#include "Libraries/graphics.h"

class Player : public Entity_Fall {
    public:
        Player(int x = 0, int y = 0, Graphics* graphics = NULL);
        void update(Map& map, const Uint8* keys);
};

#endif
