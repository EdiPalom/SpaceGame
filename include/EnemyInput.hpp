#ifndef ENEMY_INPUT_H
#define ENEMY_INPUT_H

#include <vector>

#include <SDL2/SDL.h>
#include <EntityComponent.hpp>
#include <Entity.hpp>
#include <AttackEntity.hpp>
#include <Timer.hpp>
#include <Enemy.hpp>

class EnemyInput: public EntityComponent
{
    public:
        EnemyInput(AttackEntity *actor);

        void update(Entity &actor, double dt) override;

    uint8_t choice();

    static std::vector<uint8_t> path;
    static uint8_t index;
    static uint8_t pattern;

private:
    Timer s_timer;
        AttackEntity *_actor;
    uint8_t pos;

};

#endif
