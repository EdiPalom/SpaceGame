

#include<ResourceManager.hpp>

#include <cstdio>


#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

// #define
// #include "stb_image.h"

std::map<std::string, std::shared_ptr<Texture>> ResourceManager::m_Textures;

void ResourceManager::free_memory()
{
    if(!m_Textures.empty())
    {
        m_Textures.clear();
    }
}

SDL_Texture* ResourceManager::get_texture(std::string name)
{
    auto it = m_Textures.find(name);
    if(it != m_Textures.end())
        return it->second->get_ptr();

    //TODO: return an empty texture;
}

bool ResourceManager::load_texture(std::string path, std::string name, bool alpha, SDL_Renderer *renderer)
{
    int req_format = 0; 
    if(alpha)
        req_format = STBI_rgb_alpha;
    else
        req_format = STBI_rgb;

    int width, height, orig_format;
    unsigned char* data = stbi_load(path.c_str(), &width, &height, &orig_format, req_format);

    // {
    //     int width, height, channels;
    //     stbi_info(path.c_str(), &width, &height, &channels);
    //     fprintf(stdout, "width: %d height: %d channels: %d\n",width,height,channels);
    //
    // } 

    if(data == NULL) {
        std::cout << "Loading image failed: /n" << stbi_failure_reason() << std::endl;
        return false;
    }

    // Set up the pixel format color masks for RGB(A) byte arrays.
    // Only STBI_rgb (3) and STBI_rgb_alpha (4) are supported here!
    Uint32 rmask, gmask, bmask, amask;
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    int shift = (req_format == STBI_rgb) ? 8 : 0;
    rmask = 0xff000000 >> shift;
    gmask = 0x00ff0000 >> shift;
    bmask = 0x0000ff00 >> shift;
    amask = 0x000000ff >> shift;
#else // little endian, like x86
    rmask = 0x000000ff;
    gmask = 0x0000ff00;
    bmask = 0x00ff0000;
    amask = (req_format == STBI_rgb) ? 0 : 0xff000000;
#endif

    int depth, pitch;
    if (req_format == STBI_rgb) {
    depth = 24;
    pitch = 3*width; // 3 bytes per pixel * pixels per row
    } else { // STBI_rgb_alpha (RGBA)
    depth = 32;
    pitch = 4*width;
    }

    SDL_Surface* surface = SDL_CreateRGBSurfaceFrom((void*)data, width, height, depth, pitch,
                                                rmask, gmask, bmask, amask);

    if (surface == NULL) {

        std::cout << "Creating surface failed: \n" << SDL_GetError() << std::endl;
        stbi_image_free(data);
        return false;
    }
    
    SDL_Texture *image = SDL_CreateTextureFromSurface(renderer, surface);

    m_Textures[name] = std::make_shared<Texture>(width,height,image);

    // SDL_DestroyTexture(image);
    // when you don't need the surface anymore, free it..
    SDL_FreeSurface(surface);
    // .. *and* the data used by the surface!
    stbi_image_free(data);

    return true;
}

