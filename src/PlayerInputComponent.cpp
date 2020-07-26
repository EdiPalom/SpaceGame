#include <PlayerInputComponent.hpp>
#include <iostream>

PlayerInputComponent::PlayerInputComponent(AttackEntity* actor)
{
    s_type = "input";
    _actor = actor;
}

void PlayerInputComponent::update(Entity &actor, double dt)
{
    const uint8_t *state = SDL_GetKeyboardState(NULL);
    
    sf::Vector2f m_direction = sf::Vector2f(0.f,0.f);

    actor.set_direction(m_direction);

    // std::cout << actor.get_direction().x << std::endl;
    // std::cout << "updating component" << std::endl;

    if(state[SDL_SCANCODE_LEFT])
    {
        m_direction.x = -1.0f;
        actor.set_direction(m_direction);
    }
    
    if(state[SDL_SCANCODE_RIGHT])
    {
        m_direction.x = 1.0f;
        actor.set_direction(m_direction);
    }

    if(state[SDL_SCANCODE_UP])
    {
        m_direction.y = -1.0f;
        actor.set_direction(m_direction);
    }

    if(state[SDL_SCANCODE_DOWN])
    {
        m_direction.y = 1.0f;
        actor.set_direction(m_direction);
    }

    if(state[SDL_SCANCODE_SPACE])
    {
        _actor->set_shoot(true);
    }
}
