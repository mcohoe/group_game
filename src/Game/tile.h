//This file is the header file for a tile on the map. 

#ifndef TILE_H
#define TILE_H

#include "Libraries/sprite.h"
#include "Libraries/graphics.h"

class Tile {

   public:
        enum Id{Air, Stone};
        Tile(Id to_set = Air, Graphics * graphics_ = NULL);
        void change_tile(Id to_set);
        void display_at(int x, int y);


        static const int TILE_WIDTH = 32;
        static const int TILE_HEIGHT = 32; 

   private:
        Sprite sprite;
        bool solid;
        Id id;
        Graphics * graphics;





};



#endif
