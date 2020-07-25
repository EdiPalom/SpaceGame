

#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <iostream>

#include <Vector2.hpp>
#include <Renderer.hpp>

class Entity
{
    public:
        Entity(std::string name);

        Entity(SDL_Texture *texture,bool is_visible = false, sf::Vector2i size = sf::Vector2i(0,0), sf::Vector2f position = sf::Vector2f(0,0));

        void update(double dt);
        void draw(Renderer *);
        virtual void update_current(double dt){};

    protected:
        std::string name;

    private:
        SDL_Texture* texture;
        sf::Vector2f direction, position;
        SDL_Rect sprite;
        bool visible;
};

#endif
