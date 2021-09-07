#include <Shoot.hpp>

Shoot::Shoot(AttackEntity* actor,float f_speed, float m_shoot):power(0.f),max_power(200.0f),fire_speed(f_speed),min_shoot(m_shoot)
{
   s_type = "shoot";
   _actor = actor;
}

void Shoot::update(Entity &actor, double dt)
{
    this->power += this->fire_speed;
    if(this->power >= this->max_power)
        this->power = this->max_power;

    // if(actor.get_shoot())
    if(_actor->is_shooting())
    {
        if(this->power >= this->min_shoot)
        {
            // GameState::create_bullet(this->position);
            // BulletsBuffer::add(this->position, this->i_type);
            sf::Vector2f m_position = sf::Vector2f(0.f,0.f);
            m_position.x = actor.get_position().x + (actor.get_size().x / 2);
            m_position.y = actor.get_position().y + (actor.get_size().y / 2);
            // std::cout << actor.get_position().x << " " << actor.get_position().y << std::endl;
            // m_position.y = actor.get_position().y + (actor.get_size().y / 2);
            // if(actor.get_type() == PLAYER)   
            //     SoundEngine::play(SoundEngine::shoot);
            std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>(actor.get_type(),m_position,actor.get_id());
            bullet->add_component(std::make_shared<Movable>(sf::Vector2f(0,BULLET_SPEED)));
            World::list.push_back(bullet);
            this->power = 0;
        }

        _actor->set_shoot(false);
    }
}
