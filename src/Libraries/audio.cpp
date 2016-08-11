// This is the implementation file for audio

#include "audio.h"

#include <SDL2/SDL.h>

#include <iostream>
#include <thread>
#include <chrono>

bool Audio::initialized;

// Sets up SDL_Mixer
Audio::Audio()
{
    // Start SDL_Mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cout << "Error starting audio.  SDL error: " << Mix_GetError() << "\n";
    }
    // Successful startup
    else {
        initialized = true;
    }
}

// Quit music and SDL_Mixer
Audio::~Audio()
{
    initialized = false;
    stop_music();
    Mix_Quit();
}

// Play sound effect
void Audio::play_sound(std::string filename, int volume)
{
    // Load sound
    Mix_Chunk* sound = Mix_LoadWAV(filename.c_str());
    if (sound == NULL) {
        std::cout << "Could not open sound " << filename << ".\n";
        std::cout << "SDL error: " << Mix_GetError();
        return;
    }
    // Set volume
    sound->volume = volume;
    // Play sound in new thread (so the sound can free itself on its own time)
    std::thread sound_thread(play_sound_internal, sound);
    sound_thread.detach();
}

// Play sound effect and free it once it finishes
void Audio::play_sound_internal(Mix_Chunk* sound)
{
    // Play sound
    int channel = Mix_PlayChannel(-1, sound, 0);
    // Every second, check if the sound is finished playing
    while (Mix_Playing(channel) != 0) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    // Unload sound
    Mix_FreeChunk(sound);
}

// Play music
void Audio::play_music(std::string filename, int volume)
{
    // If music is playing, stop it first
    if (music != NULL) stop_music();
    // Load new music
    music = Mix_LoadMUS(filename.c_str());
    if (music == NULL) {
        std::cout << "Could not open music " << filename << ".\n";
        std::cout << "SDL error: " << Mix_GetError();
        return;
    }
    // Set volume and play
    Mix_VolumeMusic(volume);
    Mix_PlayMusic(music, -1);
}

// Stop playing music
void Audio::stop_music(int fadeout)
{
    // If no music is playing, nothing needs to happen
    if (music == NULL) {
        return;
    }
    // If stopping with a fadeout
    if (fadeout) {
        // Fadeout in new thread (so it can unload the sound on its own time)
        std::thread music_thread(fade_music_internal, this, fadeout);
        music_thread.detach();
    }
    // If stopping normally
    else {
        // If currently fading out
        if (!fade_lock.try_lock()) {
            stop_fading = true;
            // Wait for fading thread to stop
            fade_lock.lock();
            fade_lock.unlock();
        }
        // If not fading out
        else {
            // We accidentally got the lock here so we need to unlock it
            fade_lock.unlock();
            // Stop music
            Mix_HaltMusic();
            Mix_FreeMusic(music);
            music = NULL;
        }
    }
}

// Fade out music
void Audio::fade_music_internal(int fadeout)
{
    // Stop if already fading
    if (fade_lock.try_lock()) {
        Mix_FadeOutMusic(fadeout);
        // Check every tick if we need to stop
        for (int i = 0; i < fadeout; i++) {
            SDL_Delay(1);
            if (stop_fading) {
                stop_fading = false;
                break;
            }
        }
        // Stop music
        Mix_HaltMusic();
        Mix_FreeMusic(music);
        music = NULL;
        fade_lock.unlock();
    }
}
