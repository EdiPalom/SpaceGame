
#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H


class StateMachine
{

    public:

        StateMachine();
        enum class State : char {
            MENU, TRANSITION, RUNNING
        } state = State::MENU;

        void process_event();

    private:

};


#endif
