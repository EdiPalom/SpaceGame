#include <SoundEngine.hpp>


// std::map<std::string,Mix_Music*> SoundEngine::playlist;
// std::map<std::string,Mix_Chunk*> SoundEngine::sounds;

std::map<std::string,std::shared_ptr<Music>> SoundEngine::playlist;
std::map<std::string,std::shared_ptr<Sound>> SoundEngine::sounds;

bool SoundEngine::initialize()
{

    int flags = MIX_INIT_OGG;
    int initted = Mix_Init(flags);
    if(initted&flags != flags)
    {
        std::cout << "Mixer Failed to Init ogg support" << std::endl;
        std::cout << Mix_GetError() << std::endl;
        return false;
    }

    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,1024)==-1)
    {
        std::cout << Mix_GetError() << std::endl;
        free_memory();
        return false;
    }

    Mix_AllocateChannels(2);

    return true;
}

bool SoundEngine::load_music(std::string path)
{
    // std::string delimiter = "/";
    // std::string token = path.substr(15,path.find(delimiter));
    std::string token = path.substr(14);
    Mix_Music *music = Mix_LoadMUS(path.c_str());
    if(!music)
    {
            std::cout << Mix_GetError() << std::endl;
            return false;
    }

    std::shared_ptr<Music> music_file = std::make_shared<Music>(music);

    SoundEngine::playlist.insert(std::pair<std::string,std::shared_ptr<Music>>(token, music_file));
    // SoundEngine::playlist.insert(std::pair<std::string,Mix_Music*>(token, music));

    return true;
    // SoundEngine::playlist.insert(std::pair<)
}

bool SoundEngine::load_sound(std::string path)
{
    // std::string delimiter = "/";
    // std::string token = path.substr(15,path.find(delimiter));
    std::string token = path.substr(14);

    Mix_Chunk *sound = Mix_LoadWAV(path.c_str());
    if(!sound)
    {
            std::cout << Mix_GetError() << std::endl;
            return false;
    }
    //
    std::shared_ptr<Sound> sound_file = std::make_shared<Sound>(sound);

    SoundEngine::sounds.insert(std::pair<std::string,std::shared_ptr<Sound>>(token, sound_file));
    // SoundEngine::playlist.insert(std::pair<std::string,Mix_Chunk*>(token, sound));

    return true;
    // SoundEngine::playlist.insert(std::pair<)
}

// void SoundEngine::play(ISoundSource *sound,bool loop)
void SoundEngine::play_music(std::string name,bool loop)
{
    name += ".ogg";

    auto it = SoundEngine::playlist.find(name);
    if(it != SoundEngine::playlist.end())
    {
        if(loop)
            Mix_PlayMusic((it)->second->music, -1);
            // Mix_PlayMusic((*it).second, -1);
        else
            Mix_PlayMusic((it)->second->music, 0);
            // Mix_PlayMusic((*it).second, 0);
    }
    // SoundEngine::sound_engine->play2D(sound,loop);
}

void SoundEngine::play_sound(std::string name)
{
    name += ".ogg";

    auto it = SoundEngine::sounds.find(name);
    if(it != SoundEngine::sounds.end())
    {
        // if(Mix_PlayChannel(-1,))
        if(Mix_PlayChannel(-1,(it)->second->sound,0)==-1)
        {
            Mix_PlayChannel(1,(it)->second->sound,0);
        }
    }
}

void SoundEngine::stop()
{
    // SoundEngine::sound_engine->stopAllSounds();
    // Mix_HaltChannel(0);
    // Mix_HaltChannel(1);
    Mix_HaltMusic();
}

void SoundEngine::pause()
{
    Mix_PauseMusic();
    // SoundEngine::sound_engine->setAllSoundsPaused(true);
}

void SoundEngine::resume()
{
    Mix_ResumeMusic();
    // SoundEngine::sound_engine->setAllSoundsPaused(false);
}

void SoundEngine::free_memory()
{
    // Mix_Volume(0,0);
    // Mix_Volume(1,0);
    SoundEngine::stop();
    // Mix_FreeMusic(music);
    // music = NULL;
    // std::map<std::string,Mix_Music*>::iterator it;
    // std::map<std::string,Mix_Music*>::iterator it = SoundEngine::playlist.begin();
   
    // for(it = SoundEngine::playlist.begin(); it != SoundEngine::playlist.end();it++)
    // {
    //     delete ((*it).second);
    //     (*it).second = nullptr;
    // }
    // while(it != SoundEngine::playlist.end())
    // {
    //     Mix_FreeMusic((*it).second);
    //     // delete ((*it).second);
    //     (*it).second = nullptr;
    //     ++it;
    // }

    SoundEngine::playlist.clear();
    SoundEngine::sounds.clear();

    Mix_CloseAudio();
    Mix_Quit();
    // SoundEngine::sound_engine->removeAllSoundSources();
    // SoundEngine::sound_engine->drop();
}


