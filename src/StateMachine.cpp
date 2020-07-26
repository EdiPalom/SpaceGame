
#include <StateMachine.hpp>
#include <iostream>

StateMachine::StateMachine()
{
    process_event();
    // state = State::MENU;
    prev_state = state;
}

void StateMachine::process_event()
{
    switch(state)
    {
        default: break;

        case State::INTRO:
            World::list.push_back(std::make_shared<FadeIn>(10));
            break;

        case State::MENU:
            World::list.push_back(std::make_shared<Menu>());
        break;

        case State::FADE_IN_STATE:
            World::list.push_back(std::make_shared<FadeIn>(1000));
        break;

        case State::FADE_OUT_STATE:
            World::list.push_back(std::make_shared<Entity>("Fade Out"));
        break;

        case State::RUNNING:
                World::root.push_back(std::make_shared<Running>());
        break;
    }
}

void StateMachine::update_state(int new_state)
{
    keep_state();

    switch(new_state) 
    {
        default: break;

        case FADE_IN_EVENT:
                state = State::FADE_IN_STATE;
            break;

        case FADE_OUT_EVENT:
                state = State::FADE_OUT_STATE;
            break;

        case CHANGE_SCENE:

            World::free_memory();

            if (prev_state == State::MENU)
            {
                state = State::RUNNING;
            }
            else
            {
                state = State::MENU;
            }
        break;
    }

    process_event();
}

void StateMachine::keep_state()
{
    if(state == State::MENU || state == State::RUNNING)
        prev_state = state;
}
