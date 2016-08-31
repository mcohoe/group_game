// This is the header file for the player.

#ifndef PLAYER_H
#define PLAYER_H

#include "entity_fall.h"

class Player : public Entity_Fall {
    public:
        void update(Map& map, Uint8* keys);
};

#endif
