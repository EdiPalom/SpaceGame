#ifndef BACKGROUND_MOVEMENT_H
#define BACKGROUND_MOVEMENT_H

#include <EntityComponent.hpp>
#include <Entity.hpp>

class BackgroundMovement: public EntityComponent
{
    public:
        BackgroundMovement();
        void update(Entity &entity, double dt) override;
};

#endif
