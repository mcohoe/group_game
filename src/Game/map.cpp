//Implementation of the map

#include "map.h"

//COnstructor fro the map. Currently builds a preset map
Map::Map(Graphics * graphics)
{
    //Builds simple map where the bottom three rows are stone.
    for(int x = 0; x < WIDTH; x++){
        for(int y = 0; y < HEIGHT; y++){
            Hitbox tile_hitbox(x * Tile::TILE_WIDTH, y * Tile::TILE_HEIGHT, Tile::TILE_WIDTH, Tile::TILE_HEIGHT);
            if(y >= HEIGHT-3)
                tiles[x][y] = Tile(Tile::Stone, graphics, tile_hitbox);
            else
                tiles[x][y] = Tile(Tile::Sky, graphics, tile_hitbox);
            tiles[x][y].display_at(x*Tile::TILE_WIDTH, y*Tile::TILE_HEIGHT); 
        }
    }
}

bool Map::colliding_with(int x, int y, Hitbox other)
{
    return tiles[x][y].colliding_with(other);
}
