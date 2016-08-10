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
        // Color key image
        SDL_SetColorKey(temp_surface, SDL_TRUE, SDL_MapRGB(temp_surface->format, 0, 0xFE, 0));
        // Create texture
        texture = SDL_CreateTextureFromSurface(graphics->get_renderer(), temp_surface);
        if (texture == NULL) {
            std::cout << "Unable to to get texture from image " << filename << "\n";
            std::cout << "SDL error: " << SDL_GetError() << "\n";
        }
        else {
            // Add to graphic's sprite list
            graphics->add_sprite(this);
            // Set texture width and height
            int w, h;
            SDL_QueryTexture(texture, NULL, NULL, &w, &h);
            texture_width = w;
            texture_height = h;
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

// Get rectangle of specific sprite to use on texture
SDL_Rect* Sprite::get_sprite_rect()
{
    // Get width and height of current sprite
    int w, h;
    w = texture_width / sprite_sheet_width;
    h = texture_height / sprite_sheet_height;
    sprite_rect.w = w;
    sprite_rect.h = h;
    // Get x and y of current sprite
    sprite_rect.x = w * sprite_sheet_x;
    sprite_rect.y = h * sprite_sheet_y;
    return &sprite_rect;
}

// Get rectangle of where on the screen the sprite needs to get drawn
SDL_Rect* Sprite::get_screen_rect()
{
    // Get width and height of current sprite
    int w, h;
    w = texture_width / sprite_sheet_width;
    h = texture_height / sprite_sheet_height;
    screen_rect.w = w;
    screen_rect.h = h;
    // x and y are set in other places
    return &screen_rect;
}
