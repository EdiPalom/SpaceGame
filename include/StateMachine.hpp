
#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <vector>

#include <World.hpp>
#include <FadeIn.hpp>
#include <ResourceManager.hpp>
#include <GameEvents.h>
#include <Running.hpp>
#include <Menu.hpp>

// #include <GameStates.h>



class StateMachine
{

    public:

        StateMachine();
        ~StateMachine();

        enum class State : char {
            INTRO = 0, MENU, FADE_IN_STATE, FADE_OUT_STATE, RUNNING
        };

        void process_event();
        void update_state(int new_state);
        StateMachine::State get_state(){return this->state;}

    private:

        State prev_state;
        State state;
        
        void keep_state();
};


#endif
