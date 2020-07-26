
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
        void draw(Renderer *);
        bool is_active(){return active;}
        void remove_entities();

    private:
        StateMachine state_machine;
        bool active;
};

#endif
