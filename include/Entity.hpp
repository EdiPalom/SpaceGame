

#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <iostream>

#include <Vector2.hpp>
#include <Renderer.hpp>
#include <Globals.h>

class Entity
{
    public:
        Entity(std::string name);

        Entity(SDL_Texture *texture, sf::Vector2i size = sf::Vector2i(WINDOW_WIDTH,WINDOW_HEIGHT), sf::Vector2f position = sf::Vector2f(0,0), sf::Vector2f direction = sf::Vector2f(0,0));

        void update(double dt);
        void draw(Renderer *);
        virtual void update_current(double dt){};

    protected:
        std::string name;
        bool visible;
        SDL_Texture* texture;

    private:
        sf::Vector2f direction, position;
        SDL_Rect sprite;

};

#endif
