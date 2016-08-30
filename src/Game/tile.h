//This file is the header file for a tile on the map. 

#ifndef TILE_H
#define TILE_H

#include "Libraries/sprite.h"
#include "Libraries/graphics.h"
#include "hitbox.h"

class Tile {

   public:
        enum Id{Empty, Sky, Stone};                           //enum that holds every possible tile type
        Tile(Id to_set = Empty, Graphics * graphics_ = NULL, Hitbox hitbox_ = Hitbox()); //constructor that takes in a tile id and the graphics. Builds an empty tile if none are passed in.
        void change_tile(Id to_set);                          //function that changes the tile type
        void display_at(int x, int y);                        //function that sets the tile's sprite's x and y 

        static const int TILE_WIDTH = 32;                     //width of a tile
        static const int TILE_HEIGHT = 32;                    //height of a tile

   private:
        Sprite sprite;                                      //sprite of the tile
        bool solid;                                         //boolean that says whether or not the tile is solid
        Id id;                                              //Tile Id
        Graphics * graphics;                                //pointer to the graphics
        Hitbox hitbox;





};



#endif
