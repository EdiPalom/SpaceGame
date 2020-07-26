#ifndef PLANET_ANIMATION_H
#define PLANET_ANIMATION_H

#include <vector>
#include <Vector2.hpp>
#include <SDL2/SDL.h>
#include <EntityComponent.hpp>
#include <Animation.hpp>

class PlanetAnimation:public EntityComponent,public Animation
{
    public:
        PlanetAnimation(sf::Vector2i entity_size, sf::Vector2i sheet_size, unsigned int start_frame = 0);

        void update(Entity &entity, double dt) override;
        void start_animation() override;

    private:
        bool activate;
};

#endif
