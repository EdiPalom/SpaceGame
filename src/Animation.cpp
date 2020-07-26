#include <Animation.hpp>
#include <iostream>

Animation::Animation(sf::Vector2i entity_size, sf::Vector2i sheet_size, unsigned int start_frame)
{
    // current_time = SDL_GetTicks(); 
    // last_time = 0;
    // counter_time = 0;
    FPS = 20;
    MS_PER_SECOND = (1/FPS) * 1000;

    timer = 0;
  
    delta_time = 0;

    frame = start_frame;
    static_frame = start_frame;
    tiles = 0;
    // this->fps = 500;
    get_coordinates(entity_size, sheet_size);
}

void Animation::get_coordinates(sf::Vector2i entity_size, sf::Vector2i sheet_size)
{
    for (auto y = 0; y < sheet_size.y; y+= entity_size.y)
    {
        for(auto x = 0; x < sheet_size.x; x+= entity_size.x)
        {
            coordinates.push_back(sf::Vector2i(x,y));
            ++tiles;
        }
    }
}

