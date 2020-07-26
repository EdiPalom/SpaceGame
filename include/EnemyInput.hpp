#ifndef ENEMY_INPUT_H
#define ENEMY_INPUT_H

#include <SDL2/SDL.h>
#include <EntityComponent.hpp>
#include <Entity.hpp>
#include <AttackEntity.hpp>

class EnemyInput: public EntityComponent
{
    public:
        EnemyInput(AttackEntity *actor);

        void update(Entity &actor, double dt) override;

    private:
        AttackEntity *_actor;
};

#endif
