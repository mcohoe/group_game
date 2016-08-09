// This file contains main.

#include <iostream>
#include "../Libraries/graphics.h"

int main(int argc, char* args[])
{
    // Initialize graphics
    Graphics graphics;
    // If an error occured while initializing graphics
    if (!graphics.get_initialized()) {
        std::cout << "An error occured while initializing graphics.";
        return 1;
    }
    SDL_Delay(2000); // Just for testing right now
    return 0;
}
