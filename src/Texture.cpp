

#include <Texture.hpp>

Texture::Texture(uint width, uint height, SDL_Texture *image)
{
    this->texture = image;
    this->width = width;
    this->height = height;
}

Texture::~Texture()
{
    if(this->texture != NULL)
        SDL_DestroyTexture(this->texture);
}
