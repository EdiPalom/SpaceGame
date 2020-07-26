

#ifndef MOVEX_H
#define MOVEX_H

#include <cstdlib>

#include <Entity.hpp>

class MoveX:public Entity
{
    public:
        MoveX(Entity *entity, float target_position, unsigned int speed);
        void update_current(double dt) override;

    private:
        Entity *_actor;
        float _target;
        unsigned int _speed;
};

#endif
