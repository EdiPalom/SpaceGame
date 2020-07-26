#ifndef PLAYERINPUTCOMPONENT_H
#define PLAYERINPUTCOMPONENT_H

#include <SDL2/SDL.h>
#include <EntityComponent.hpp>
#include <Entity.hpp>
#include <AttackEntity.hpp>

class PlayerInputComponent: public EntityComponent
{
    public:
        PlayerInputComponent(AttackEntity* actor);

        void update(Entity &actor, double dt) override;

    private:
        AttackEntity *_actor;
};

#endif
