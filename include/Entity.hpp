

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
        static uint16_t p_layer;
    
        Entity(std::string name);

        Entity(SDL_Texture *texture, sf::Vector2i size = sf::Vector2i(WINDOW_WIDTH,WINDOW_HEIGHT), sf::Vector2f position = sf::Vector2f(0,0), sf::Vector2f direction = sf::Vector2f(0,0));

        void update(double dt);
        void draw(Renderer *);
        virtual void update_current(double dt){};

    void set_position(sf::Vector2f position){this->position = position;}
        void set_direction(sf::Vector2f direction){this->direction = direction;}
        void set_atlas_position(sf::Vector2i position){this->sprite.x = position.x; this->sprite.y = position.y;}
        void set_destroy(bool status){b_destroy = status;}
        void set_alpha(uint8_t alpha);
    void set_name(std::string name){this->name = name;}
        
        sf::Vector2f get_position(){return this->position;}
        sf::Vector2f get_direction(){return this->direction;}
        sf::Vector2f get_size(){return sf::Vector2f(sprite.w, sprite.h);}
        sf::Vector2f get_body(){return body_size;}
    sf::Vector2f get_body_position(){return sf::Vector2f(this->position.x + this->body_d.x, this->position.y + this->body_d.y);}
    
        bool get_destroy(){return b_destroy;}
        ENTITY_TYPE get_type(void){return type;}
        uint16_t get_id(){return this->id;}

    std::string get_name(){return this->name;}

        virtual void set_collision(bool c){this->b_destroy = c;}

        static uint16_t get_random_color();

    protected:
        std::string name;
        bool visible;
        SDL_Texture* texture;
        sf::Vector2f direction, position;
        SDL_Rect sprite;
        bool b_destroy;
        ENTITY_TYPE type;
        uint16_t id;

    private:
        sf::Vector2f body_size;
        sf::Vector2f body_d;
};

#endif
