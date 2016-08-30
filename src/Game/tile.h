//This file is the header file for a tile on the map. 

#ifndef TILE_H
#define TILE_H

#include "Libraries/sprite.h"

class Tile {

   public:
        enum Id{Air, Stone};
        Sprite(Id id = Air);
        void change_tile(Id to_set);
        

   private:
        static const int TILE_WIDTH = 32;
        static const int TILE_HEIGHT = 32;
        Sprite sprite;
        bool solid;
        Id id;





};



#endif
