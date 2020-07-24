
#include <StateMachine.hpp>
#include <iostream>

StateMachine::StateMachine()
{

}

void StateMachine::process_event()
{
    switch(state)
    {
        default: break;

        case State::MENU:
            std::cout << "Menu" << std::endl;
                 // state = State::TRANSITION;
        break;

        case State::TRANSITION:
            std::cout << "Transition" << std::endl;
                // state = State::RUNNING;
        break;

        case State::RUNNING:
            std::cout << "Running" << std::endl;
        break;
    }
}
