#ifndef SOUND_H
#define SOUND_H

#include <SDL2/SDL_mixer.h>

class Sound
{
    public:
        Sound(Mix_Chunk *);
        ~Sound();
    // private:
        Mix_Chunk* sound;
};

#endif
