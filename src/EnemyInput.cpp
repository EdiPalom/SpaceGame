#include "EnemyInput.hpp"

EnemyInput::EnemyInput(AttackEntity *actor)
{
    s_type = "input";
    _actor = actor;
}

void EnemyInput::update(Entity &actor, double dt)
{
    _actor->set_shoot(true);
}
