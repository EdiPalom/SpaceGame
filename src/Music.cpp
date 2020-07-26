#include <Music.hpp>

Music::Music(Mix_Music* music_ptr)
{
    music = music_ptr;
}

Music::~Music()
{
    // delete(music);
    Mix_FreeMusic(music);
    music = nullptr;
}
