// This file contains main.

#include <iostream>
#include "../Libraries/graphics.h"
#include "../Libraries/sprite.h"

int main(int argc, char* args[])
{
    // Initialize graphics
    Graphics graphics;
    // If an error occured while initializing graphics
    if (!Graphics::get_initialized()) {
        std::cout << "An error occured while initializing graphics.";
        return 1;
    }
    const Uint8* keys = SDL_GetKeyboardState(NULL); // Keys being pressed
    bool quit = false; // set to true when quitting the program
    // Just for testing at the moment:
    int x = 0;
    int y = 0;
    Sprite test("Graphics/Test.png", &graphics);
    test.set_xy(x, y);
    test.set_sprite_sheet(3, 2);
    Sprite test2("Graphics/Test2.png", &graphics);
    test2.set_xy(50, 50);
    test2.set_z(10);
    // Event used to handle sdl events
    SDL_Event e;
    // Main loop
    while (!quit) {
        // Quit if needed
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
        // Move in the direction you press
        if (keys[SDL_SCANCODE_DOWN]) y += 1;
        if (keys[SDL_SCANCODE_LEFT]) x -= 1;
        if (keys[SDL_SCANCODE_RIGHT]) x += 1;
        if (keys[SDL_SCANCODE_UP]) y -= 1;
        test.set_xy(x, y);

        graphics.update();
    }
    return 0;
}
