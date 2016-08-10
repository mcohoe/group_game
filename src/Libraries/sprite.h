// This is the header file for sprites.

#ifndef SPRITE_H
#define SPRITE_H

#include "graphics.h"

#include <string>

class Sprite
{
    SDL_Texture* texture = NULL; // The image that the sprite shows
    SDL_Rect rect; // The rectangle representing the image
    int z = 0; // The order images appear on the screen
    Graphics* graphics; // The graphics used by the game
    public:
        Sprite(std::string filename, Graphics* g); // Sets up the sprite with the graphic "filename"
        ~Sprite(); // Destroys texture and removes sprite from the sprite list
        void update(unsigned int x, unsigned int y); // Updates the x and y values of the sprite
        int get_z() {return z;}
        void set_z(int to_set) {z = to_set;}
        SDL_Texture* get_texture() {return texture;}
        SDL_Rect* get_rect() {return &rect;}
};

#endif
