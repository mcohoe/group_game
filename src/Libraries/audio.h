// This is the header file for anything related to audio

#include <SDL2/SDL_mixer.h>

#include <string>

class Audio {
    Mix_Music* music = NULL;
    static void play_sound_internal(Mix_Chunk*);
    static bool initialized;
    public:
        Audio();
        ~Audio();
        void play_sound(std::string filename, int volume = 128);
        void play_music(std::string filename, int volume = 128);
        void stop_music(int fadeout = 0);
        static bool get_initialized() {return initialized;}
};
