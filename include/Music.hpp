#ifndef MUSIC_H
#define MUSIC_H

#include <SDL2/SDL_mixer.h>

class Music
{
    public:
        Music(Mix_Music *);
        ~Music();
    // private:
        Mix_Music* music;
};

#endif
