

#include <EnemyFactory.hpp>

// EnemyFactory::EnemyFactory()
// {
//
// }
//
// EnemyFactory::~EnemyFactory()
// {
//
// }

void EnemyFactory::create(sf::Vector2f position, int limit)
{
    sf::Vector2f m_position(0.f,0.f);

    for (auto i = 0; i < limit; ++i) 
    {
        std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>(m_position);

        m_position.x = (position.x + enemy->get_size().x) * i;
        m_position.y = position.y;

        enemy->set_position(m_position);
        enemy->add_component(std::make_shared<Movable>(sf::Vector2f(ENEMY_SPEED,ENEMY_SPEED)));
        // enemy->add_component(std::make_shared<Shoot>(enemy.get()));
        enemy->add_component(std::make_shared<EnemyInput>(enemy.get()));

        World::list.push_back(enemy);
    }
}


