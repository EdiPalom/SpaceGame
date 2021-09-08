
#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <vector>

#include <World.hpp>
#include <FadeIn.hpp>
#include <ResourceManager.hpp>
#include <GameEvents.h>
#include <Running.hpp>
#include <Menu.hpp>
#include <GameOver.hpp>

// #include <GameStates.h>



class StateMachine
{

    public:

        StateMachine();
        ~StateMachine();

        enum{
            INTRO = 0, MENU, FADE_IN_STATE, FADE_OUT_STATE, RUNNING, GAMEOVER
        };

        void process_event();
        void update_state(int new_state);
        uint8_t get_state(){return this->state;}

    private:

        uint8_t prev_state;
        uint8_t state;
        
        void keep_state();
};


#endif
