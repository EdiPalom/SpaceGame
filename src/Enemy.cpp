


#include <Enemy.hpp>

//uint8_t Enemy::pattern = 79;

Enemy::Enemy(sf::Vector2f position,sf::Vector2f direction,uint8_t i):ActorEntity(ResourceManager::get_texture("sheet")->get_ptr(), sf::Vector2i(95,93),position,direction),AttackEntity(i)
{
    this->type = ENEMY;
    this->sprite.x = 101;
    this->id = p_layer;
}

void Enemy::update_current(double dt)
{
    ActorEntity::update_current(dt);

    if(this->position.x >= WINDOW_WIDTH - this->sprite.w)
        this->direction.x = -1.f;
    else if (this->position.x <= 0)
        this->direction.x = 1.f;
}

