#include <Movable.hpp>
// #include <iostream>

Movable::Movable(sf::Vector2f speed)
{
    s_type = "movable";
    _speed = speed;
}

void Movable::update(Entity &entity, double dt)
{
    sf::Vector2f position = entity.get_position(); 
    sf::Vector2f direction = entity.get_direction();
    // position.x = position.x + direction.x * (_speed.x * dt);
    // position.y = position.y + direction.y * (_speed.y * dt);
    position.x = position.x + direction.x * _speed.x;
    position.y = position.y + direction.y * _speed.y;
    entity.set_position(position);
}
