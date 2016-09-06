//This fille is the implementation of the header file for the tile class.

#include "tile.h"

//contrstuctor that takes in a tile id and the graphics. Builds an air tile if none are passed in.
Tile::Tile(Id to_set, Graphics * graphics_, Hitbox hitbox_)
{
     graphics = graphics_;
     change_tile(to_set);
     hitbox = hitbox_;
}
//function that changes the tile type
void Tile::change_tile(Id to_set)
{
    id = to_set;
    switch(to_set){
        case Empty:
            sprite = Sprite("", NULL);
            solid = false;
            break;

        case Sky:
            sprite = Sprite("Graphics/Sky.png", graphics);
            solid = false;
            break;

        case Stone:
            sprite = Sprite("Graphics/Stone.png", graphics);
            solid = true;
            break; 
    }
    return;
}

//boolean that says whether or not the tile is solid
void Tile::display_at(int x, int y)
{
    sprite.set_xy(x,y);
}

bool Tile::colliding_with(const Hitbox& other)
{
    if (solid) {
        if (hitbox.is_touching(other)) return true;
    }
    return false;
}

bool Tile::colliding_side(const Hitbox& other, Hitbox::Direction to_check)
{
    if (solid) {
        if (other.touching_side(hitbox, to_check)) return true;
    }
    return false;
}
