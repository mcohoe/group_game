// This is the header file for sprites.

#ifndef SPRITE_H
#define SPRITE_H

#include "graphics.h"

#include <string>
#include <vector>
#include <utility>

// Animations are just a vector of pairs of x and y sprite sheet values
typedef std::vector<std::pair<int, int>> Animation;

class Sprite
{
    SDL_Texture* texture = NULL; // The image that the sprite shows
    SDL_Rect sprite_rect; // Rectangle representing the part of the texture to use
    SDL_Rect screen_rect; // Rectangle for where on the screen the sprite should go
    int texture_width; // Width of the texture
    int texture_height; // Height of the texture
    int sprite_sheet_width = 1; // How many sprites are on the texture horizontally
    int sprite_sheet_height = 1; // How many sprites are on the texture vertically
    int sprite_sheet_x = 0; // Which sprite this is on the sprite sheet horizontally
    int sprite_sheet_y = 0; // Which sprite this is on the sprite sheet vertically
    int z = 0; // The order images appear on the screen
    Graphics* graphics; // The graphics used by the game
    Animation current_animation; // The animation currently being played
    unsigned int animation_count = 0; // The current frame of the animation being played
    public:
        Sprite(std::string filename, Graphics* g); // Sets up the sprite with the graphic "filename"
        ~Sprite(); // Destroys texture and removes sprite from the sprite list
        void set_xy(int x, int y) {screen_rect.x = x; screen_rect.y = y;} 
        int get_z() {return z;}
        void set_z(int to_set) {z = to_set;}
        void set_sprite_sheet(int w, int h) {sprite_sheet_width = w; sprite_sheet_height = h;}
        void set_sprite_sheet_xy(int x, int y) {sprite_sheet_x = x; sprite_sheet_y = y;}
        SDL_Texture* get_texture() {return texture;}
        SDL_Rect* get_sprite_rect(); // Get rectangle of the texture being used
        SDL_Rect* get_screen_rect(); // Get rectangle of screen position
        void start_animation(Animation); // Start playing an animation
        void stop_animation(); // Stop playing an animation
        void update_animation(); // Update the current animation
};

#endif
