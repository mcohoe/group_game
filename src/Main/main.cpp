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
    test.set_xy(0, 0);
    test.set_sprite_sheet(3, 2);
    graphics.update();
    SDL_Delay(500);
    test.set_sprite_sheet_xy(1, 0);
    graphics.update();
    SDL_Delay(500);
    test.set_sprite_sheet_xy(2, 0);
    graphics.update();
    SDL_Delay(500);
    test.set_sprite_sheet_xy(0, 1);
    graphics.update();
    SDL_Delay(500);
    test.set_sprite_sheet_xy(1, 1);
    graphics.update();
    SDL_Delay(500);
    test.set_sprite_sheet_xy(2, 1);
    graphics.update();
    SDL_Delay(1000);

    return 0;
}
