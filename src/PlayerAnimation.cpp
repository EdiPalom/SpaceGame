#include <PlayerAnimation.hpp>
#include <iostream>

PlayerAnimation::PlayerAnimation(sf::Vector2i entity_size, sf::Vector2i sheet_size, unsigned int start_frame):Animation(entity_size,sheet_size,start_frame)
{
    s_type = "animation";
}

void PlayerAnimation::update(Entity& entity, double dt)
{
    // delta_time += dt;
    //
    // if(delta_time >= MS_PER_SECOND)
    {
        if(entity.get_direction().x == 0)
        {
            if(frame < static_frame)
                ++frame;
            else if(frame > static_frame)
                -- frame;
        }
        if(entity.get_direction().x == -1)
        {
            if(frame != 0)
            {
                --frame;
            }
        }
        if(entity.get_direction().x == 1)
        {
            if(frame < 11)
            {

                ++frame;
            }
            // ++frame;
        }

        // entity.set_atlas_position(coordinates[frame % frame_loop]);
        entity.set_atlas_position(coordinates[frame % 12]);

        // delta_time -= MS_PER_SECOND;
    }
}
