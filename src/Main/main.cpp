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
    // Just for testing at the moment:
    Sprite test("Graphics/Test.png", &graphics);
    test.update(0, 0);
    graphics.update();
    SDL_Delay(2000);

    return 0;
}
