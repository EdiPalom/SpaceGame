
#include <EntityAnimated.hpp>

EntityAnimated::EntityAnimated(SDL_Texture *texture, sf::Vector2f position, sf::Vector2i size):ActorEntity(texture,size,position)
{
    // this->position = position;
    // this->sprite.w = size.x;
    // this->sprite.h = size.y;
}

void EntityAnimated::start_animation()
{
    // std::shared_ptr<EntityComponent> component = this->get_component("animation").lock();
    // if(component)
    // {
    //     component->start_animation();
    // }
}


