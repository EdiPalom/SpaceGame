
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

    int e_limit = 7;
    EnemyFactory::create(sf::Vector2f(0,30),sf::Vector2f(1,0),e_limit);

    sf::Vector2f p_position = sf::Vector2f(30,5);
    std::shared_ptr<Entity> plife = std::make_shared<Entity>(ResourceManager::get_texture("player_life")->get_ptr(),ResourceManager::get_texture("player_life")->get_size(),p_position);
    plife->set_name("plife1");
    World::list.push_back(plife);

    std::shared_ptr<Entity> plife2 = std::make_shared<Entity>(*plife);
    plife2->set_position(sf::Vector2f(p_position.x + 30,p_position.y));
    plife2->set_name("plife2");
    World::list.push_back(plife2);

    std::shared_ptr<Entity> plife3 = std::make_shared<Entity>(*plife);
    plife3->set_position(sf::Vector2f(p_position.x + 60,p_position.y));
    plife3->set_name("plife3");
    World::list.push_back(plife3);

    //World::remove_entity("plife1");
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
            SoundEngine::play_sound("Accept");
            EventManager::set_event(FADE_IN_EVENT);
            break;
    }
}
