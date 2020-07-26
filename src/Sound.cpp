#include <Sound.hpp>

Sound::Sound(Mix_Chunk* sound_ptr)
{
    sound = sound_ptr;
}

Sound::~Sound()
{
    // delete(music);
    Mix_FreeChunk(sound);
    sound = nullptr;
}
