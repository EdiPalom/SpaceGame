#include <PlanetAnimation.hpp>
#include <iostream>

PlanetAnimation::PlanetAnimation(sf::Vector2i entity_size, sf::Vector2i sheet_size, unsigned int start_frame):Animation(entity_size, sheet_size,start_frame)
{
    this->FPS = 25;
    // this->MS_PER_SECOND = (1000/FPS) / 10000;
    // this->MS_PER_SECOND = (1/FPS) * 1000;
    this->MS_PER_SECOND = 1000/FPS;
    activate = true;
    s_type = "animation";
}

void PlanetAnimation::update(Entity& entity, double dt)
{
    if(activate)
    {
        ++frame;
        activate = false;
        delta_time = 0;
    }else
    {
        if(frame > static_frame || frame < static_frame)
        {
            delta_time += dt;
            if(delta_time >= MS_PER_SECOND)
            {
                ++frame;
                frame %= tiles;
                entity.set_atlas_position(coordinates[frame]);
                delta_time -= MS_PER_SECOND;
            }
        }
    }
}

void PlanetAnimation::start_animation()
{
    activate = true;
}
