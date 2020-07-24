
#ifndef GAME_H
#define GAME_H

#include <StateMachine.hpp>

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
