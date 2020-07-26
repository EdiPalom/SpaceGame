
#include <Running.hpp>

Running::Running():Entity(ResourceManager::get_texture("background")->get_ptr())
{
    Background slow("back_small", BACK_SLOW_SPEED);
    Background medium("back_medium", BACK_MEDIUM_SPEED);
    Background fast("back_big", BACK_FAST_SPEED);

    std::shared_ptr<Player> player = std::make_shared<Player>();
    player->add_component(std::make_shared<PlayerInputComponent>(player.get()));
    player->add_component(std::make_shared<Movable>(sf::Vector2f(PLAYER_SPEED,PLAYER_SPEED)));
    player->add_component(std::make_shared<PlayerAnimation>());
    player->add_component(std::make_shared<Shoot>(player.get(),4,70));
    World::list.push_back(player);

    EnemyFactory::create(sf::Vector2f(0,50), 5);
}

void Running::update_current(double dt)
{
    handle_input();
}

void Running::handle_input()
{
    switch(Keyboard::get_key())
    {
        default: break;

        case KEY_ESCAPE:
            EventManager::set_event(FADE_IN_EVENT);
            break;
    }
}
