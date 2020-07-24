
#ifndef GAME_H
#define GAME_H

#include <StateMachine.hpp>
#include <World.hpp>
#include <EventManager.hpp>

class Game
{
    public:
        Game();

        bool initialize();
        void update(double dt);
        void draw();

    private:
        StateMachine state_machine;
};

#endif
