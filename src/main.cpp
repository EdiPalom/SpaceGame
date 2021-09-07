// #define SDL_MAIN_HANDLED

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

#include <Game.hpp>
#include <Window.hpp>
#include <Renderer.hpp>
#include <ResourceManager.hpp>
#include <Keyboard.hpp>
#include <SoundEngine.hpp>

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
static bool active = true;

static void must_init(bool test, std::string description)
{
    if(test) return;
    std::cout << "couldn't initialize " << description << std::endl;
    exit(1);
}

static void free_resources()
{
    SoundEngine::free_memory();
    World::free_memory();
    ResourceManager::free_memory();
    SDL_Quit();
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
                active = false;
            }
            break;

            case SDL_KEYDOWN:
                switch(event->key.keysym.sym)
                {
                    default: break;

                    case SDLK_ESCAPE:
                        Keyboard::set_key(KEY_ESCAPE);
                        break;

                    case SDLK_RETURN:
                        Keyboard::set_key(KEY_RETURN);
                        break;

                    case SDLK_DOWN:
                        Keyboard::set_key(KEY_DOWN);
                        break;

                    case SDLK_UP:
                        Keyboard::set_key(KEY_UP);
                        break;
                }
                break;
        }
    }
}



static bool load_resources(SDL_Renderer* renderer)
{
    bool success = true;

    success = ResourceManager::load_texture("assets/images/background.png","background", true, renderer);
    success = ResourceManager::load_texture("assets/images/menu.png","menu", true, renderer);
    success = ResourceManager::load_texture("assets/images/menu_play.png","menu_play", true, renderer);
    success = ResourceManager::load_texture("assets/images/menu_exit.png","menu_exit", true, renderer);
    success = ResourceManager::load_texture("assets/images/stars_small.png","back_small", true, renderer);
    success = ResourceManager::load_texture("assets/images/stars_medium.png","back_medium", true, renderer);
    success = ResourceManager::load_texture("assets/images/stars_big.png","back_big", true, renderer);
    success = ResourceManager::load_texture("assets/images/red_ship.png","player", true, renderer);
    success = ResourceManager::load_texture("assets/images/sheet3.png","sheet", true, renderer);
    success = ResourceManager::load_texture("assets/images/Planet1.png","planet1", true, renderer);
    success = ResourceManager::load_texture("assets/images/Planet2.png","planet2", true, renderer);
    success = ResourceManager::load_texture("assets/images/Earth.png","earth", true, renderer);

    success = SoundEngine::load_music("assets/sounds/BlindShift.ogg");
    success = SoundEngine::load_music("assets/sounds/Cybermatic.ogg");

    success = SoundEngine::load_sound("assets/sounds/Accept.ogg");
    success = SoundEngine::load_sound("assets/sounds/GUI_1.ogg");
    success = SoundEngine::load_sound("assets/sounds/laser.ogg");

    return success;
}

int main()
{
    srand(time(NULL));
    must_init(!SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO), "SDL Library");

    must_init(SoundEngine::initialize(), "Sound Engine");

    Window window;
    must_init(window.created != NULL,"SDL Window");

    Renderer renderer(window.get_ptr());
    must_init(renderer.get_ptr() != NULL, "SDL Renderer");

    Game game;
    must_init(game.initialize(), "Game App");

    must_init(load_resources(renderer.get_ptr()),"Loading Resources");

    SDL_Event event;

    SoundEngine::play_music("BlindShift",true);

    while(game.is_active() && active)
    {
        current_time = SDL_GetTicks();
        delta_time = current_time - last_time;
        last_time = current_time;
        counter_time += delta_time;
        ups_lag += delta_time;

        process_events(&event);

        // EventManager::print();

        if(ups_lag >= MS_PER_SECOND)
        {
            game.update(delta_time);
            ++ups;

            ups_lag -= MS_PER_SECOND;
        }
        
        renderer.clear();
        game.draw(&renderer);
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

    free_resources();

    return 0;
}

