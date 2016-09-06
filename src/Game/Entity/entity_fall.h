// Header for entities that fall normall

#ifndef ENTITY_FALL_H
#define ENTITY_FALL_H

#include "entity.h"

class Entity_Fall : public Entity {
    public:
        Entity_Fall(int x, int y) : Entity(x, y) {}
        virtual void update(Map& map);

        static const int GRAVITY = 5;
    protected:
        bool on_ground;
};

#endif
