// This is the header file for entities.

#ifndef ENTITY_H
#define ENTITY_H

#include "Game/tile.h"
#include "Game/hitbox.h"
#include "Libraries/sprite.h"

class Entity {
    public:
        Entity(int x = 0, int y = 0);
        virtual void update();

        static const int PIXEL_WIDTH = 16;
        static const int PIXEL_HEIGHT = 16;
        static const int TILE_WIDTH = Tile::TILE_WIDTH;
        static const int TILE_HEIGHT = Tile::TILE_HEIGHT;
        static const int MAX_X_VEL = 40;
        static const int MAX_Y_VEL = 100;

    private:
        int subpixel_x = 0;
        int subpixel_y = 0;
        int pixel_x = 0;
        int pixel_y = 0;
        int tile_x = 0;
        int tile_y = 0;
        int x_vel = 0;
        int y_vel = 0;
        int x_accel = 0;
        int y_accel = 0;
        Sprite sprite;
        Hitbox hitbox;

        int screen_x();
        int screen_y();
};

#endif
