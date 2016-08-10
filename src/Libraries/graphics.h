// This is the header file for any graphics-related functions.

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>

#include <list>

class Sprite; // To be able to make the sprite list

class Graphics
{
    // Screen height and width
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    // The window and renderer the game renders to
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    static bool initialized; // This is true while the graphics are operational

    std::list<Sprite*> sprites; // The sprites on the screen

    public:
        Graphics(); // Initializes the window for use
        ~Graphics(); // Destroys the window being used
        void update(); // Redraws the screen
        void add_sprite(Sprite* s) {sprites.push_back(s);} // Add a sprite to the sprite list
        void remove_sprite(Sprite* s); // Remove a sprite from the sprite list
        static bool get_initialized() {return initialized;}
        SDL_Renderer* get_renderer() {return renderer;}
};

#endif
