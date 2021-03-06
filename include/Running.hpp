

#ifndef RUNNING_H
#define RUNNING_H

#include <Entity.hpp>
#include <ResourceManager.hpp>
#include <Background.hpp>
#include <Keyboard.hpp>
#include <EventManager.hpp>

#include <Player.hpp>
#include <PlayerInputComponent.hpp>
#include <PlayerAnimation.hpp>

#include <EnemyFactory.hpp>

class Running:public Entity
{
    public:
        Running();
        ~Running();

        void update_current(double dt) override;
        void handle_input();


};

#endif
