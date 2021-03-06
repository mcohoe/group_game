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
    public:
        Sprite(std::string filename = "", Graphics* g = NULL); // Sets up the sprite with the graphic "filename"
        ~Sprite(); // Destroys texture and removes sprite from the sprite list
        // Disable any kind of copying
        Sprite& operator=(const Sprite&) = delete;
        Sprite(const Sprite&) = delete;
        // Move constructors:
        Sprite& operator=(Sprite&&);
        Sprite(Sprite&&);

        void set_xy(int x, int y) {screen_rect.x = x; screen_rect.y = y;} 
        int get_z() {return z;}
        void set_z(int to_set) {z = to_set;}
        void set_sprite_sheet(int w, int h) {sprite_sheet_width = w; sprite_sheet_height = h;}
        void set_current_sprite_xy(int x, int y) {current_sprite_x = x; current_sprite_y = y;}
        SDL_Texture* get_texture() {return texture;}
        SDL_Rect* get_sprite_rect(); // Get rectangle of the texture being used
        SDL_Rect* get_screen_rect(); // Get rectangle of screen position
        void start_animation(Animation); // Start playing an animation
        void stop_animation(); // Stop playing an animation
        void update_animation(); // Update the current animation
    private:
        SDL_Texture* texture = NULL; // The image that the sprite shows
        SDL_Rect sprite_rect; // Rectangle representing the part of the texture to use
        SDL_Rect screen_rect; // Rectangle for where on the screen the sprite should go
        int texture_width; // Width of the texture
        int texture_height; // Height of the texture
        int sprite_sheet_width = 1; // How many sprites are on the texture horizontally
        int sprite_sheet_height = 1; // How many sprites are on the texture vertically
        int current_sprite_x = 0; // Which sprite this is on the sprite sheet horizontally
        int current_sprite_y = 0; // Which sprite this is on the sprite sheet vertically
        int z = 0; // The order images appear on the screen
        Graphics* graphics = NULL; // The graphics used by the game
        Animation current_animation; // The animation currently being played
        unsigned int animation_count = 0; // The current frame of the animation being played
};

#endif
