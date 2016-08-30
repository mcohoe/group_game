// This is the header file for any graphics-related functions.

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>

#include <list>

class Sprite; // To be able to make the sprite list

class Graphics
{
    public:
        Graphics(); // Initializes the window for use
        ~Graphics(); // Destroys the window being used
        // Disable any kind of copying
        Graphics& operator=(const Graphics&) = delete;
        Graphics(const Graphics&) = delete;

        // Screen height and width
        static const int SCREEN_WIDTH = 640;
        static const int SCREEN_HEIGHT = 480;
        // Framerate
        static const int FRAMERATE = 60;
        static const int TICKS_PER_FRAME = 1000 / FRAMERATE;

        void update(); // Redraws the screen and waits for the frame to finish
        void add_sprite(Sprite* s) {sprites.push_back(s);} // Add a sprite to the sprite list
        void remove_sprite(Sprite* s); // Remove a sprite from the sprite list
        static bool get_initialized() {return initialized;}
        SDL_Renderer* get_renderer() {return renderer;}

    private:
        int current_frame_start_ticks = 0; // How many ticks it's taken to get to this frame
        // The window and renderer the game renders to
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;

        static bool initialized; // This is true while the graphics are operational

        std::list<Sprite*> sprites; // The sprites on the screen
};

#endif
