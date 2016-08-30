//Implementation of the map

#include "map.h"

//COnstructor fro the map. Currently builds a preset map
Map::Map(Graphics * graphics)
{
    //Builds simple map where the bottom three rows are stone.
    for(int x = 0; x < WIDTH; x++){
        for(int y = 0; y < HEIGHT; y++){
            if(y >= HEIGHT-3)
                tiles[x][y] = Tile(Tile::Stone, graphics);
            else
                tiles[x][y] = Tile();
            tiles[x][y].display_at(x*Tile::TILE_WIDTH, y*Tile::TILE_HEIGHT); 
        }
    }
}
