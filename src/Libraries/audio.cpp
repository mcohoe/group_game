// This is the implementation file for audio

#include "audio.h"

#include <iostream>
#include <thread>
#include <chrono>

bool Audio::initialized;

Audio::Audio()
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cout << "Error starting audio.  SDL error: " << Mix_GetError() << "\n";
    }
    else {
        initialized = true;
    }
}

Audio::~Audio()
{
    stop_music();
}

void Audio::play_sound(std::string filename, int volume)
{
    Mix_Chunk* sound = Mix_LoadWAV(filename.c_str());
    if (sound == NULL) {
        std::cout << "Could not open sound " << filename << ".\n";
        std::cout << "SDL error: " << Mix_GetError();
        return;
    }
    sound->volume = volume;
    std::thread sound_thread(play_sound_internal, sound);
    sound_thread.detach();
}

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

void Audio::play_music(std::string filename, int volume)
{
    if (music != NULL) stop_music();
    music = Mix_LoadMUS(filename.c_str());
    if (music == NULL) {
        std::cout << "Could not open music " << filename << ".\n";
        std::cout << "SDL error: " << Mix_GetError();
        return;
    }
    Mix_VolumeMusic(volume);
    Mix_PlayMusic(music, -1);
}

void Audio::stop_music(int fadeout)
{
    if (music == NULL) return;
    if (fadeout) {
        // TODO
    }
    else {
        Mix_HaltMusic();
        Mix_FreeMusic(music);
        music = NULL;
    }
}
