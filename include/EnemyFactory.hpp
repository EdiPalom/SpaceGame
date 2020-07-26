

#ifndef ENEMY_FACTORY_H
#define ENEMY_FACTORY_H

#include <Enemy.hpp>
#include <Movable.hpp>
#include <Shoot.hpp>
#include <EnemyInput.hpp>
#include <World.hpp>

class EnemyFactory
{
    public:
        // EnemyFactory();
        // ~EnemyFactory();

        static void create(sf::Vector2f position, int limit);
};

#endif
