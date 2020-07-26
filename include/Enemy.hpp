
#ifndef ENEMY_H
#define ENEMY_H

#include <ActorEntity.hpp>
#include <AttackEntity.hpp>

#include <ResourceManager.hpp>

class Enemy:public ActorEntity,public AttackEntity
{
    public:
        Enemy(sf::Vector2f position);
        void update_current(double dt) override;
};

#endif
