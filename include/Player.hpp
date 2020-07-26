

#ifndef PLAYER_H
#define PLAYER_H

#include <ActorEntity.hpp>
#include <AttackEntity.hpp>
#include <ResourceManager.hpp>

class Player:public ActorEntity, public AttackEntity
{
    public:
        Player();
        void update_current(double dt) override;
};

#endif
