

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

        static void create(sf::Vector2f position,sf::Vector2f direction, int limit);
    static std::shared_ptr<Enemy> create_enemy(sf::Vector2f position,sf::Vector2f direction,int i);
};

#endif
