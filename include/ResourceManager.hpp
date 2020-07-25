

#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <memory>
#include <map>
#include <string>
#include <iostream>

#include <SDL2/SDL_render.h>

#include <Vector2.hpp>

// #define STB_IMAGE_IMPLEMENTATION
// #include <stb_image.h>

#include <Texture.hpp>

class ResourceManager
{

    public:
        static bool load_texture(std::string path, std::string name, bool alpha, SDL_Renderer* renderer);
        static SDL_Texture* get_texture(std::string name);
        static void free_memory();
        static sf::Vector2i get_texture_size(std::string name){return m_Textures[name]->get_size();}

    private:
        // static std::map<std::string, SDL_Texture *> m_Textures;
        static std::map<std::string, std::shared_ptr<Texture>> m_Textures;
};

#endif
