#ifndef PLAYER_ANIMATION_H
#define PLAYER_ANIMATION_H

#include <vector>
#include <Vector2.hpp>
#include <SDL2/SDL.h>
#include <EntityComponent.hpp>
#include <Animation.hpp>

class PlayerAnimation:public EntityComponent,public Animation
{
    public:
        PlayerAnimation(sf::Vector2i entity_size = sf::Vector2i(115,86),sf::Vector2i sheet_size = sf::Vector2i(345,344),unsigned int frame = 6);
        void update(Entity &entity, double dt) override;
};

#endif
