// This is the implemenation file for anything relating to graphics.

#include "graphics.h"
#include <iostream>
#include <algorithm>

#include "sprite.h"

bool Graphics::initialized;

// This function initializes everything needed to be able to draw graphics.
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
            // Get renderer 
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (renderer == NULL) {
                std::cout << "Error: Renderer could not be created.\nSDL_Error:";
                std::cout << SDL_GetError() << "\n";
            }
            else {
                // Set initial screen values
                SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
                initialized = true;
            }
        }
    }
}

// This function destroys the window and quits SDL.
Graphics::~Graphics()
{
    // Destroy window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    // Quit SDL
    SDL_Quit();

    initialized = false;
}

// This function redraws the screen
void Graphics::update()
{
    // Clear screen
    SDL_RenderClear(renderer);
    // Sort the sprites by z coordinate
    sprites.sort([](Sprite* a, Sprite* b) {return a->get_z() < b->get_z();});
    // Draw all sprites
    for (Sprite* s : sprites) {
        SDL_RenderCopy(renderer, s->get_texture(), NULL, s->get_rect());
    }
    // Update screen
    SDL_RenderPresent(renderer);
}

// Removes a sprite from the sprite list
void Graphics::remove_sprite(Sprite* s)
{
    // Find the iterator representing this sprite in the list
    auto it = sprites.begin();
    while (it != sprites.end()) {
        // If the correct element
        if (*it == s) {
            sprites.erase(it);
            return;
        }
        else it++;
    }
}
