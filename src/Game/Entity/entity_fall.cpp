// This is the implementation file for entities that fall.

#include "entity_fall.h"

void Entity_Fall::update(Map& map)
{
    if (on_ground) {
        y_accel = 0;
        y_vel = 0;
    }
    else y_accel = GRAVITY;

    on_ground = map.colliding_side(hitbox, Hitbox::Down);

    Entity::update(map);
}
