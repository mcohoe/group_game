// This is the implementation file for sprites.

#include "sprite.h"

#include <iostream>

#include <SDL2/SDL_image.h>

// Create sprite with the graphic "filename"
Sprite::Sprite(std::string filename, Graphics* g)
{
    graphics = g;
    // Load image
    SDL_Surface* temp_surface = IMG_Load(filename.c_str());
    if (temp_surface == NULL) {
        std::cout << "Unable to load image " << filename << "\n";
        std::cout << "SDL_image error: " << IMG_GetError() << "\n";
    }
    else {
        // Create texture
        texture = SDL_CreateTextureFromSurface(graphics->get_renderer(), temp_surface);
        if (texture == NULL) {
            std::cout << "Unable to to get texture from image " << filename << "\n";
            std::cout << "SDL error: " << SDL_GetError() << "\n";
        }
        else {
            // Add to graphic's sprite list
            graphics->add_sprite(this);
            // Create rectangle
            int w, h;
            SDL_QueryTexture(texture, NULL, NULL, &w, &h);
            rect.w = w;
            rect.h = h;
        }
        // Free the image
        SDL_FreeSurface(temp_surface);
    }
}

// Destroys the texture held by the sprite and removes the sprite from the sprite list
Sprite::~Sprite()
{
    SDL_DestroyTexture(texture);
    // If graphics are still running
    if (Graphics::get_initialized()) {
        graphics->remove_sprite(this);
    }
}

// Updates the x and y values of the sprite
void Sprite::update(unsigned int x, unsigned int y)
{
    rect.x = x;
    rect.y = y;
}
