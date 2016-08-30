// This is the implementation file for sprites.

#include "sprite.h"

#include <iostream>

#include <SDL2/SDL_image.h>

// Create sprite with the graphic "filename"
Sprite::Sprite(std::string filename, Graphics* g)
{
    // If making a fake sprite, the constructor shouldn't do anything
    if (filename == "" or g == NULL) {
        return;
    }

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
    if (texture != NULL) {
        SDL_DestroyTexture(texture);
    }
    // If graphics are still running
    if (graphics != NULL and Graphics::get_initialized()) {
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
    sprite_rect.x = w * current_sprite_x;
    sprite_rect.y = h * current_sprite_y;
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

// Start playing an animation
void Sprite::start_animation(Animation anime)
{
    current_animation = anime;
    animation_count = 0;
}

// Stop playing an animation
void Sprite::stop_animation()
{
    current_animation.clear();
    animation_count = 0;
}

// Update the current animation
void Sprite::update_animation()
{
    // If no animation is playing, don't update the animation
    if (current_animation.size() == 0) return;

    // Go to next frame in animation
    animation_count += 1;
    if (animation_count >= current_animation.size()) {
        animation_count = 0;
    }
    // Set sprite sheet values to the animation's values
    current_sprite_x = current_animation[animation_count].first;
    current_sprite_y = current_animation[animation_count].second;
}
