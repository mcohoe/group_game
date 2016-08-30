//This fille is the implementation of the header file for the tile class.

#include "tile.h"

Tile::Tile(Id to_set, Graphics * graphics_)
{
     graphics = graphics_;
     change_tile(to_set);
}

void Tile::change_tile(Id to_set)
{
    id = to_set;
    switch(to_set){
        case Air:
            sprite = Sprite("", NULL);
            solid = false;
            break;

        case Stone:
            sprite = Sprite("Graphics/Stone.png", graphics);
            solid = true;
            break; 
    }
    return;
}


