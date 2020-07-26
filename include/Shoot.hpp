#ifndef SHOOT_H
#define SHOOT_H

#include <iostream>
// #include <cstdlib>

#include <EntityComponent.hpp>
#include <Bullet.hpp>
#include <Movable.hpp>
#include <AttackEntity.hpp>
#include <World.hpp>
// #include <SoundEngine.hpp>

class Shoot: public EntityComponent
{
    public:

        Shoot(AttackEntity *actor,float f_speed = rand() % 4 + 1, float m_shoot = rand() % 10 + 190);
        // Shoot(float f_speed = rand() % 4 + 1, float m_shoot = rand() % 10 + 190);
        void update(Entity &actor,double dt) override;

    private:
        AttackEntity *_actor;

        float power;
        float max_power;
        float fire_speed;
        float min_shoot;
        // bool b_shoot;

};

#endif
