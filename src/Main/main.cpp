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
    for (int i = 0; i < 200; i++) {
        graphics.update();
        test.set_xy(i, i);
    }
    return 0;
}
