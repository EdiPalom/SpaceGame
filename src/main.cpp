#define SDL_MAIN_HANDLED

#include <string>
#include <iostream>

#include <Game.hpp>
#include <Window.hpp>
#include <Renderer.hpp>

// #include <Keyboard.hpp>

static double last_time = SDL_GetTicks();
static unsigned int ups = 0;
static unsigned int fps = 0;
static double current_time = 0;
static double delta_time = 0;
static double ups_lag = 0;
static double counter_time = 0;
static const double FPS = 60;
static const double MS_PER_SECOND = (1/FPS) * 1000;

static void must_init(bool test, std::string description)
{
    if(test) return;
    std::cout << "couldn't initialize " << description << std::endl;
    exit(1);
}

static void process_events(SDL_Event* event)
{
    while(SDL_PollEvent(event))
    {
        switch(event->type)
        {
            default: break;

            case SDL_WINDOWEVENT_CLOSE:
            {
                exit(1);
            }
            break;

            case SDL_KEYDOWN:
                switch(event->key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        exit(1);
                        break;
                }
        }
    }
}

int main()
{
    must_init(!SDL_Init(SDL_INIT_VIDEO), "SDL Library");

    Window window;
    must_init(window.created != NULL,"SDL Window");

    Renderer renderer(window.get_ptr());
    must_init(renderer.created != NULL, "SDL Renderer");

    Game game;
    must_init(game.initialize(), "Game App");

    SDL_Event event;

    while(true)
    {
        current_time = SDL_GetTicks();
        delta_time = current_time - last_time;
        last_time = current_time;
        counter_time += delta_time;
        ups_lag += delta_time;

        process_events(&event);

        if(ups_lag >= MS_PER_SECOND)
        {
            game.update(delta_time);
            ++ups;

            ups_lag -= MS_PER_SECOND;
        }
        
        renderer.clear();
        game.draw();
        ++fps;
        renderer.present();

        if(counter_time >= 1000)
        {
            std::cout << "APS: " << ups << " FPS: " << fps << std::endl;
            counter_time -= 1000;
            ups = 0;
            fps = 0;
        }
    }

    return 0;
}

