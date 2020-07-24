
#include <Game.hpp>

Game::Game()
{

}

bool Game::initialize()
{
    return true;
}

void Game::update(double dt)
{
    for(long unsigned int i = 0; i < World::list.size(); ++i)
    {
        if(!World::list[i]) continue;
        World::list[i]->update(dt);
    }

    // std::cout << World::list.size() << std::endl;

    switch(EventManager::event.front())
    {
        default: break;

        case FADE_IN_EVENT:
            EventManager::request_event(FADE_IN_EVENT);
            state_machine.update_state(FADE_IN_EVENT);
            break;

        case FADE_OUT_EVENT:
            EventManager::request_event(FADE_OUT_EVENT);
            state_machine.update_state(FADE_OUT_EVENT);
            break;

        case CHANGE_SCENE:
            EventManager::request_event(CHANGE_SCENE);
            state_machine.update_state(CHANGE_SCENE);
            break;
    }
}

void Game::draw()
{

}
