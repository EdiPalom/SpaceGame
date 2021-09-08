#include "EnemyInput.hpp"

std::vector<uint8_t> EnemyInput::path = {121,115,103,79,31};
uint8_t EnemyInput::index = 2;
uint8_t EnemyInput::pattern = EnemyInput::path[EnemyInput::index];

EnemyInput::EnemyInput(AttackEntity *actor):s_timer(2000)
{
    s_type = "input";
    _actor = actor;
    this->pos = _actor->get_position();
}

uint8_t EnemyInput::choice()
{
    if(EnemyInput::index == 0)
    {
        EnemyInput::index++;        
    }
    else if(EnemyInput::index == 4)
    {
        EnemyInput::index--;        
    }
    else
    {
        if(rand()%2)
        {
            EnemyInput::index++;            
        }
        else
        {
            EnemyInput::index--;            
        }
    }

    EnemyInput::pattern = EnemyInput::path[EnemyInput::index];    
}

void EnemyInput::update(Entity &actor, double dt)
{
    uint8_t t = EnemyInput::pattern;

    if(this->pos == 0 && this->_actor->is_shooting() == false)
    {
        this->choice();
    }

    if((t >> this->pos) & 0x1)
    {
        _actor->set_shoot(true);
    }
}
