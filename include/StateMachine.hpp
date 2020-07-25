
#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <vector>

#include <World.hpp>
#include <FadeIn.hpp>
#include <ResourceManager.hpp>
#include <GameEvents.h>

// #include <GameStates.h>



class StateMachine
{

    public:

        StateMachine();

        enum class State : char {
            INTRO, MENU, FADE_IN_STATE, FADE_OUT_STATE, RUNNING
        } state = State::INTRO;

        void process_event();
        void update_state(int new_state);

    private:

        State prev_state;
        
        void keep_state();
};


#endif
