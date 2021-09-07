

#include <Bullet.hpp>
#include <Globals.h>

Bullet::Bullet(ENTITY_TYPE source,sf::Vector2f position,uint16_t id):ActorEntity(ResourceManager::get_texture("sheet")->get_ptr(),sf::Vector2i(25,50),sf::Vector2f(position.x - 15, position.y), sf::Vector2f(0,1.f))
{
    this->type = BULLET;
    this->id = id;
  
    this->sprite.x = 138;
    this->sprite.y = 85;

    if(source == PLAYER)
    {
        SoundEngine::play_sound("laser");
        this->sprite.x = 38;
        this->sprite.y = 89;
        this->position = sf::Vector2f(position.x - 19,position.y - 77);
        this->direction.y = -1.f;
    }
}

void Bullet::update_current(double dt)
{
    ActorEntity::update_current(dt);

    if(this->position.y <= 0 || (this->position.y + this->sprite.h) >= WINDOW_HEIGHT)
        this->b_destroy = true;
}
