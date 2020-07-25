

#ifndef TEXTURE_H
#define TEXTURE_H

typedef unsigned int uint;

#include <SDL2/SDL_render.h>
#include <Vector2.hpp>

class Texture
{
    public:
        Texture(uint width, uint height, SDL_Texture *texture);
        ~Texture();

        SDL_Texture *get_ptr(){return texture;}
        
        sf::Vector2i get_size(){return sf::Vector2i(width,height);}

    private:
        SDL_Texture *texture;
        uint width, height;
};

#endif

