// This is the implementation file for entities.

#include "entity.h"

Entity::Entity(int x, int y)
{
    tile_x = x;
    tile_y = y;
    sprite.set_xy(screen_x(), screen_y());
    hitbox.set_xy(pixel_x, pixel_y);
}

void Entity::update(Map& map)
{
    x_vel += x_accel;
    y_vel += y_accel;
    if (x_vel < -MAX_X_VEL) x_vel = -MAX_X_VEL;
    else if (x_vel > MAX_X_VEL) x_vel = MAX_X_VEL;
    if (y_vel < -MAX_Y_VEL) y_vel = -MAX_Y_VEL;
    else if (y_vel > MAX_Y_VEL) y_vel = MAX_Y_VEL;

    subpixel_x += x_vel;
    subpixel_y += y_vel;
    change_pixel_xy(subpixel_x, pixel_x, subpixel_x / PIXEL_SIZE - pixel_x, map);
    change_pixel_xy(subpixel_y, pixel_y, subpixel_y / PIXEL_SIZE - pixel_y, map);
    tile_x = pixel_x / TILE_WIDTH;
    tile_y = pixel_y / TILE_HEIGHT;

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

void Entity::change_pixel_xy(int& subpixel_coord, int& coord, int change, Map& map)
{
    if (change == 0) return;
    int direction = change / abs(change);
    int original_coord = coord;
    for (int i = original_coord; i != original_coord + change; i += direction) {
        coord += direction;
        hitbox.set_xy(pixel_x, pixel_y);
        if (map.colliding_with(hitbox)) {
            subpixel_coord = coord * PIXEL_SIZE;
            return;
        }
    }
}

