

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

void EnemyFactory::create(sf::Vector2f position,sf::Vector2f direction, int limit)
{
    //    sf::Vector2f m_position(0.f,0.f);

    int i = 0;

    for (i = 0; i < limit; ++i) 
    {
        // std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>(m_position);

        // m_position.x = (position.x + enemy->get_size().x) * i;
        // m_position.y = position.y;

        // enemy->set_position(m_position);
        // enemy->add_component(std::make_shared<Movable>(sf::Vector2f(ENEMY_SPEED,ENEMY_SPEED)));
        // enemy->add_component(std::make_shared<Shoot>(enemy.get(),200,200));
        // enemy->add_component(std::make_shared<EnemyInput>(enemy.get()));

        World::list.push_back(EnemyFactory::create_enemy(position,direction,i));
    }
}

std::shared_ptr<Enemy> EnemyFactory::create_enemy(sf::Vector2f position,sf::Vector2f direction,int i)
{
        sf::Vector2f m_position(0.f,0.f);
        
        std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>(m_position,direction,i);

        m_position.x = (position.x + (enemy->get_size().x * i)) + (i * 5) + 3;
        m_position.y = position.y;

        enemy->set_position(m_position);
        //enemy->add_component(std::make_shared<Movable>(sf::Vector2f(ENEMY_SPEED,ENEMY_SPEED)));
        enemy->add_component(std::make_shared<Shoot>(enemy.get(),8,200));
        enemy->add_component(std::make_shared<EnemyInput>(enemy.get()));

        return enemy;
}
