// This is the header file for anything related to audio

#include <SDL2/SDL_mixer.h>

#include <string>

#include <mutex>

class Audio {
    Mix_Music* music = NULL; // Background music
    static void play_sound_internal(Mix_Chunk*); // Actually plays sound (gets called as a new thread)
    static void fade_music_internal(Audio* self, int fadeout); // Fades music (gets called as a new thread)
    static bool initialized; // True while audio is working
    std::mutex fade_lock; // Lock used for fading music
    bool stop_fading = false; // Flag to tell the audio to stop fading
    public:
        Audio(); // Sets up SDL_Mixer
        ~Audio(); // Stops music and quit SDL_Mixer
        void play_sound(std::string filename, int volume = 128); // Play sound effect
        void play_music(std::string filename, int volume = 128); // Play music
        void stop_music(int fadeout = 0); // Stop music (with possible fadeout)
        static bool get_initialized() {return initialized;}
};
