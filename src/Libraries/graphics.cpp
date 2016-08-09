// This is the implemenation file for anything relating to graphics.

#include "graphics.h"
#include <iostream>

// This function initializes everything needed to be able to draw graphics.
// It returns true if a problem happened and it was unsuccessful.
Graphics::Graphics()
{
    // Initialize SDL (SDL_Init returns -1 on failure)
    if (SDL_Init(SDL_INIT_VIDEO) == -1) {
        std::cout << "Error: could not initialize SDL.\nSDL_Error:";
        std::cout << SDL_GetError() << "\n";
    }
    else {
        //Create window
        window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            std::cout << "Error: Window could not be created.\nSDL_Error:";
            std::cout << SDL_GetError() << "\n";
        }
        else {
            // Get surface
            surface = SDL_GetWindowSurface(window);

            initialized = true;

            // The next few lines are for testing
            // They'll be removed later
            SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
            SDL_UpdateWindowSurface(window);
        }
    }
}

// This function destroys the window and quits SDL.
Graphics::~Graphics()
{
    // Destroy window
    SDL_DestroyWindow(window);
    // Quit SDL
    SDL_Quit();
}
