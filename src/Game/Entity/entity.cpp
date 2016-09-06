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
    Hitbox::Direction x_dir, y_dir;
    if (x_vel < 0) x_dir = Hitbox::Left;
    else x_dir = Hitbox::Right;
    if (y_vel < 0) y_dir = Hitbox::Up;
    else y_dir = Hitbox::Down;
    change_pixel_xy(subpixel_x, pixel_x, subpixel_x / PIXEL_SIZE - pixel_x, x_dir, map);
    change_pixel_xy(subpixel_y, pixel_y, subpixel_y / PIXEL_SIZE - pixel_y, y_dir, map);
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

void Entity::change_pixel_xy(int& subpixel_coord, int& coord, int change, Hitbox::Direction dir, Map& map)
{
    if (change == 0) return;
    int direction = change / abs(change);
    int original_coord = coord;
    for (int i = original_coord; i != original_coord + change; i += direction) {
        if (map.colliding_side(hitbox, dir)) {
            subpixel_coord = coord * PIXEL_SIZE;
            return;
        }
        coord += direction;
        hitbox.set_xy(pixel_x, pixel_y);
    }
}

