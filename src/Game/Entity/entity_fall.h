// Header for entities that fall normall

#ifndef ENTITY_FALL_H
#define ENTITY_FALL_H

#include "entity.h"

class Entity_Fall : public Entity {
    public:
        virtual void update(Map& map);

        static const int GRAVITY = 5;
    protected:
        bool on_ground;
};

#endif