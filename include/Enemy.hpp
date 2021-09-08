
#ifndef ENEMY_H
#define ENEMY_H

#include <ActorEntity.hpp>
#include <AttackEntity.hpp>

#include <ResourceManager.hpp>

class Enemy:public ActorEntity,public AttackEntity
{
    public:
    Enemy(sf::Vector2f position,sf::Vector2f direction=sf::Vector2f(-1.0f,0.0f),uint8_t i = 0);
        void update_current(double dt) override;
};

#endif
