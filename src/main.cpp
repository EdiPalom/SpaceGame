#define SDL_MAIN_HANDLED

#include <string>
#include <iostream>

#include <Game.hpp>
#include <Window.hpp>
#include <Renderer.hpp>

// #include <Keyboard.hpp>

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
        process_events(&event);

        renderer.clear();
            
        game.draw();

        renderer.present();
    }

    return 0;
}

