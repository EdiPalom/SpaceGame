
#include <Player.hpp>

Player::Player():ActorEntity(ResourceManager::get_texture("player")->get_ptr(),sf::Vector2i(115,87),sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT * 0.8))
{
    this->sprite.y = 173;
    this->name = "Player";
}

void Player::update_current(double dt)
{
    ActorEntity::update_current(dt);

    if(this->position.x >= WINDOW_WIDTH - this->sprite.w)
    {
        this->position = sf::Vector2f(WINDOW_WIDTH - this->sprite.w, this->position.y);

    }else if (this->position.x <= 0)
    {
        this->position = sf::Vector2f(0, this->position.y);
    }

    if(this->position.y >= WINDOW_HEIGHT - this->sprite.h)
    {
        this->position = sf::Vector2f(this->position.x, WINDOW_HEIGHT - this->sprite.h);
        
    }else if (this->position.y <= 0)
    {
        this->position = sf::Vector2f(this->position.x, 0);
    }
}
