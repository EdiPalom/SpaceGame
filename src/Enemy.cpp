


#include <Enemy.hpp>

Enemy::Enemy(sf::Vector2f position):ActorEntity(ResourceManager::get_texture("sheet")->get_ptr(), sf::Vector2i(95,93),position,sf::Vector2f(-1.0f, 0.f))
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

