

#ifndef ENTITY_ANIMATED_H
#define ENTITY_ANIMATED_H

#include <ActorEntity.hpp>
#include <ResourceManager.hpp>

class EntityAnimated:public ActorEntity
{
    public:
        EntityAnimated(SDL_Texture *texture, sf::Vector2f position = sf::Vector2f(0,0), sf::Vector2i size = sf::Vector2i(100,100));
        void start_animation();
};

#endif
