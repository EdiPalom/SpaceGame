
#include <StateMachine.hpp>
#include <iostream>

StateMachine::StateMachine():state(INTRO)
{
    process_event();
    // state = State::MENU;
    prev_state = state;
}

StateMachine::~StateMachine(){}

void StateMachine::process_event()
{
    switch(state)
    {
        default: break;

        case INTRO:
            World::utils.push_back(std::make_shared<FadeIn>(5));
            break;

        case MENU:
            SoundEngine::play_music("BlindShift",true);
            World::root.push_back(std::make_shared<Menu>());
        break;

        case FADE_IN_STATE:
            World::utils.push_back(std::make_shared<FadeIn>(1000));
        break;

        case FADE_OUT_STATE:
            World::utils.push_back(std::make_shared<Entity>("Fade Out"));
        break;

        case RUNNING:
                SoundEngine::play_music("Cybermatic",true);
                World::root.push_back(std::make_shared<Running>());
        break;

        case GAMEOVER:
            World::free_list();
            World::list.push_back(std::make_shared<GameOver>());
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
                state = FADE_IN_STATE;
            break;

        case FADE_OUT_EVENT:
                state = FADE_OUT_STATE;
            break;

        case CHANGE_SCENE:

            World::free_memory();

            if (prev_state == MENU)
            {
                state = RUNNING;
            }
            else
            {
                state = MENU;
            }
        break;

    case GAME_OVER_EVENT:
        this->state = GAMEOVER;
        break;
    }

    process_event();
}

void StateMachine::keep_state()
{
    if(state == MENU || state == RUNNING)
        prev_state = state;
}
