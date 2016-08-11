// This file contains main.

#include <iostream>
#include "../Libraries/graphics.h"
#include "../Libraries/audio.h"
#include "../Libraries/sprite.h"

int main(int argc, char* args[])
{
    // Initialize graphics
    Graphics graphics;
    if (!Graphics::get_initialized()) {
        std::cout << "An error occured while initializing graphics.";
        return 1;
    }
    // Initialize graphics
    Audio audio;
    if (!Audio::get_initialized()) {
        std::cout << "An error occured while initializing audio.";
        return 1;
    }
    const Uint8* keys = SDL_GetKeyboardState(NULL); // Keys being pressed
    bool quit = false; // set to true when quitting the program
    SDL_Event e; // Event used to handle sdl events
    // Main loop
    while (!quit) {
        // Quit if needed
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Do stuff here

        graphics.update();
    }
    return 0;
}
