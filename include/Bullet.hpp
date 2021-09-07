

#ifndef BULLET_H
#define BULLET_H

#include <ActorEntity.hpp>
#include <SoundEngine.hpp>
#include <ResourceManager.hpp>

class Bullet:public ActorEntity
{
    public:
    Bullet(ENTITY_TYPE source,sf::Vector2f position,uint16_t id);
        void update_current(double dt)override;
};

#endif
