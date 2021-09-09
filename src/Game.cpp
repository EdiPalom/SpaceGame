
#include <Game.hpp>
#include <Globals.h>

Game::Game(Renderer *renderer):active(true),count(0)
{
    font = TTF_OpenFont("assets/font/Neon.ttf",14);

    this->renderer = renderer;

    SDL_Rect r = {WINDOW_WIDTH - 400, 1, 200,40};
    this->score = new Text("Score: ",r,this->font,renderer->get_ptr());

    r.x += 200;
    r.y += 8;
    r.w = 100;
    r.h = 30;
    this->counter = new Text(" ",r,this->font,renderer->get_ptr());
}

Game::~Game()
{
    TTF_CloseFont(this->font);
    this->font = NULL;
    delete score;
}

bool Game::initialize()
{
    return true;
}

void Game::update(double dt)
{
    World::update(dt);

    this->count+=1;
    this->counter->update(this->renderer->get_ptr(),std::to_string(count));

    if(state_machine.get_state() == StateMachine::RUNNING)
        physics.update();

    //std::cout << World::list.size() << std::endl;

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

    case GAME_OVER_EVENT:
        this->count = 0;        
        EventManager::request_event(GAME_OVER_EVENT);
        state_machine.update_state(GAME_OVER_EVENT);
        break;
    }
}

void Game::draw(Renderer *renderer)
{
    World::draw(renderer);
    
    if(state_machine.get_state()==StateMachine::RUNNING)
    {
        this->score->draw(renderer);
        this->counter->draw(renderer);
    }

    //physics.draw(renderer);

    // SDL_Rect srcrect = {0,0,WINDOW_WIDTH,WINDOW_HEIGHT};
    // SDL_Rect dstrect = {0,0,WINDOW_WIDTH,WINDOW_HEIGHT};

    // renderer->draw(ResourceManager::get_texture("menu"),&srcrect,&dstrect);
    // renderer->draw(ResourceManager::get_texture("menu"),NULL,&dstrect);
}

