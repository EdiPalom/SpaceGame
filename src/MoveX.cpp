

#include <MoveX.hpp>

MoveX::MoveX(Entity* entity, float target_position, unsigned int speed):Entity("move_x")
{
    _actor = entity;
    _target = target_position;
    _speed = speed;
}

void MoveX::update_current(double dt)
{
    sf::Vector2f current_position = _actor->get_position();
    if(current_position.x == _target)
    {
        this->b_destroy = true;
    }

    if(current_position.x > _target)
    {
        if(current_position.x <= (_target + 10))
            _speed = 1;
        current_position.x -= _speed;
    }else if(current_position.x < _target)
    {
        if(current_position.x >= (_target - 10))
            _speed = 1;
        current_position.x += _speed;
    }
    _actor->set_position(current_position);
}
