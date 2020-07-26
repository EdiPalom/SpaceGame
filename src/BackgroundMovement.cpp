#include <BackgroundMovement.hpp>
#include <Globals.h>

BackgroundMovement::BackgroundMovement()
{
    s_type = "physics";
}

void BackgroundMovement::update(Entity &entity, double dt)
{
    // if(entity.get_position().y > WINDOW_HEIGHT + 256)
    // {
    //     sf::Vector2f m_position = sf::Vector2f(entity.get_position().x, -254);
    //     entity.set_position(m_position);
    // }


    if(entity.get_position().y > WINDOW_HEIGHT)
    {
        sf::Vector2f m_position = sf::Vector2f(entity.get_position().x, -256);
        entity.set_position(m_position);
    }
  
}
