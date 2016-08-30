// This is the implementation file for entities.

#include "entity.h"

Entity::Entity(int x, int y)
{
    tile_x = x;
    tile_y = y;
}

void Entity::update()
{
    x_vel += x_accel;
    y_vel += y_accel;
    if (x_vel < -MAX_X_VEL) x_vel = -MAX_X_VEL;
    else if (x_vel > MAX_X_VEL) x_vel = MAX_X_VEL;
    if (y_vel < -MAX_Y_VEL) y_vel = -MAX_Y_VEL;
    else if (y_vel > MAX_Y_VEL) y_vel = MAX_Y_VEL;

    subpixel_x += x_vel;
    subpixel_y += y_vel;
    pixel_x = subpixel_x % PIXEL_WIDTH;
    pixel_y = subpixel_y % PIXEL_HEIGHT;
    tile_x = pixel_x % TILE_WIDTH;
    tile_y = pixel_y % TILE_HEIGHT;

    sprite.set_xy(screen_x(), screen_y());
    hitbox.set_xy(pixel_x, pixel_y);
}

int Entity::screen_x()
{
    return pixel_x;
}

int Entity::screen_y()
{
    return pixel_y;
}