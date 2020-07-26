

#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <iostream>

#include <Vector2.hpp>
#include <Renderer.hpp>
#include <Globals.h>
#include <EntityTypes.h>

class Entity
{
    public:
        Entity(std::string name);

        Entity(SDL_Texture *texture, sf::Vector2i size = sf::Vector2i(WINDOW_WIDTH,WINDOW_HEIGHT), sf::Vector2f position = sf::Vector2f(0,0), sf::Vector2f direction = sf::Vector2f(0,0));

        void update(double dt);
        void draw(Renderer *);
        virtual void update_current(double dt){};

        void set_position(sf::Vector2f position){this->position = position;}
        void set_direction(sf::Vector2f direction){this->direction = direction;}
        void set_atlas_position(sf::Vector2i position){this->sprite.x = position.x; this->sprite.y = position.y;}
        void set_destroy(bool status){b_destroy = status;}
        
        sf::Vector2f get_position(){return this->position;}
        sf::Vector2f get_direction(){return this->direction;}
        sf::Vector2f get_size(){return sf::Vector2f(sprite.w, sprite.h);}
        bool get_destroy(){return b_destroy;}
        ENTITY_TYPE get_type(void){return type;}

    protected:
        std::string name;
        bool visible;
        SDL_Texture* texture;
        sf::Vector2f direction, position;
        SDL_Rect sprite;
        bool b_destroy;
        ENTITY_TYPE type;

    private:




};

#endif
