#ifndef MOVABLE_H
#define MOVABLE_H

#include <Vector2.hpp>
#include <EntityComponent.hpp>

class Movable: public EntityComponent
{
    public:
        Movable(sf::Vector2f speed);
        void update(Entity &entity, double dt) override;

    private:
        sf::Vector2f _speed;
};

#endif
