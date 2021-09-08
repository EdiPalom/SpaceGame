
#include <Player.hpp>

Player::Player():ActorEntity(ResourceManager::get_texture("player")->get_ptr(),sf::Vector2i(115,87),sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT * 0.8)),collision_timer(2000)
{
    this->sprite.y = 173;
    this->type = PLAYER;
    this->name = "Player";
    this->id = Entity::get_random_color();
    this->life = 3;
    this->b_collision = true;
}

void Player::set_collision(bool c)
{
    if(c && this->b_collision)
    {
        if(this->life != 0)
        {
            World::remove_entity("plife"+std::to_string(this->life));
            SoundEngine::play_sound("metal");
            this->life--;
            this->b_collision = false;
        }
    }

    if(this->life == 0)
    {
        this->b_destroy = true;
        EventManager::set_event(GAME_OVER_EVENT);
    }
}

void Player::update_current(double dt)
{
    ActorEntity::update_current(dt);

    if (this->collision_timer.get_signal(dt))
    {
        this->b_collision  = true;
    }      

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
