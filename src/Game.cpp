
#include <Game.hpp>
#include <Globals.h>

Game::Game():active(true)
{

}

bool Game::initialize()
{
    return true;
}

void Game::update(double dt)
{

    for(long unsigned int i = 0; i < World::root.size(); ++i)
    {
        if(!World::root[i]) continue;
        World::root[i]->update(dt);
    }

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

        case CLOSE:
            active = false;
            break;
    }
}

void Game::draw(Renderer *renderer)
{

    for(long unsigned int i = 0; i < World::root.size(); ++i)
    {
        if(!World::root[i]) continue;
        World::root[i]->draw(renderer);
    }

    for(long unsigned int i = 0; i < World::list.size(); ++i)
    {
        if(!World::list[i]) continue;
        World::list[i]->draw(renderer);
    }
    //
    // SDL_Rect srcrect = {0,0,WINDOW_WIDTH,WINDOW_HEIGHT};
    // SDL_Rect dstrect = {0,0,WINDOW_WIDTH,WINDOW_HEIGHT};

    // renderer->draw(ResourceManager::get_texture("menu"),&srcrect,&dstrect);
    // renderer->draw(ResourceManager::get_texture("menu"),NULL,&dstrect);
}
