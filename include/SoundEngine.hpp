#ifndef SOUND_ENGINE_H
#define SOUND_ENGINE_H

#include <string>
#include <map>
#include <memory>
#include <iostream>
#include <Music.hpp>
#include <Sound.hpp>
// #include <SDL2/SDL_mixer.h>


class SoundEngine
{
    public:
        static bool initialize();
        static void play_music(std::string name,bool loop = false);
        static void play_sound(std::string name);

        static bool load_music(std::string path);
        static bool load_sound(std::string path);
        // static void play(ISoundSource *sound,bool loop = false);
        static void stop();
        static void pause();
        static void resume();
        static void free_memory();

        // static std::map<std::string,Mix_Music*> playlist;
        // static std::map<std::string,Mix_Chunk*> sounds;
        static std::map<std::string,std::shared_ptr<Music>> playlist;
        static std::map<std::string,std::shared_ptr<Sound>> sounds;
};

#endif
