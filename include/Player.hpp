

#ifndef PLAYER_H
#define PLAYER_H

#include <ActorEntity.hpp>
#include <AttackEntity.hpp>
#include <ResourceManager.hpp>
#include <World.hpp>
#include <Timer.hpp>
#include <SoundEngine.hpp>

class Player:public ActorEntity, public AttackEntity
{
    public:
        Player();
        void update_current(double dt) override;
    void set_collision(bool c) override;

private:
    uint8_t life;
    bool b_collision;

    Timer collision_timer;
};

#endif
