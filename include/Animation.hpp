#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>
#include <Vector2.hpp>
#include <SDL2/SDL.h>

class Animation
{
    public:
        Animation(sf::Vector2i entity_size, sf::Vector2i sheet_size, unsigned int start_frame);

    protected:
        void get_coordinates(sf::Vector2i entity_size, sf::Vector2i sheet_size);

        double delta_time;
        double FPS;
        double MS_PER_SECOND;

        unsigned int frame;
        unsigned int static_frame;
        unsigned int tiles;

        double timer;
        // unsigned int fps;
        // std::vector<coord> coordinates;
        std::vector<sf::Vector2i> coordinates;

        // glm::vec2 m_size;
};

#endif
