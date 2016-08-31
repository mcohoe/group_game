//This file is the header file for the game map

#ifndef MAP_H
#define MAP_H

#include "Libraries/graphics.h"
#include "tile.h"

class Map {

    public:
        Map(Graphics * graphics); //constructor (currently builds single preset map)
        bool colliding_with(const Hitbox& other);
        bool colliding_side(const Hitbox& other, Hitbox::Direction to_check);

        static const int WIDTH = Graphics::SCREEN_WIDTH/Tile::TILE_WIDTH; //amount of tiles horizontally on screen
        static const int HEIGHT = Graphics::SCREEN_HEIGHT/Tile::TILE_HEIGHT; //amount of tiles vertically on tiles
        

    private:

        Tile tiles[WIDTH][HEIGHT]; //2 dimentional array of each tile



};



#endif
