// This is the header file for any graphics-related functions.

#include <SDL2/SDL.h>

class Graphics
{
    // Screen height and width
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    // The window and screen the game renders to
    SDL_Window* window;
    SDL_Surface* surface;

    bool initialized = false; // This is set to true at the end of the constructor to say that it was initialized correctly

    public:
        bool get_initialized() {return initialized;}
        Graphics(); // Initializes the window for use
        ~Graphics(); // Destroys the window being used
};
