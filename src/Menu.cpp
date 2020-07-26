

#include <Menu.hpp>

Menu::Menu():Entity(ResourceManager::get_texture("menu_play")->get_ptr())
{
    sf::Vector2i size = sf::Vector2i(130,130);
    sf::Vector2f position = sf::Vector2f(30, 195);
    sf::Vector2i sheet_size = ResourceManager::get_texture("planet1")->get_size();

    this->planet1 = std::make_shared<EntityAnimated>(ResourceManager::get_texture("planet1")->get_ptr(),position,size);
    // planet1->add_component(std::make_shared<PlanetAnimation>(size, sheet_size));

    size = sf::Vector2i(175,175);
    position = sf::Vector2f(504, 120);
    sheet_size = ResourceManager::get_texture("planet2")->get_size();

    this->planet2 = std::make_shared<EntityAnimated>(ResourceManager::get_texture("planet2")->get_ptr(),position,size);

    size = sf::Vector2i(350,350);
    position = sf::Vector2f(438, 295);
    sheet_size = ResourceManager::get_texture("earth")->get_size();

    this->earth = std::make_shared<EntityAnimated>(ResourceManager::get_texture("earth")->get_ptr(),position,size);

    World::list.push_back(this->planet1);
    World::list.push_back(this->planet2);
    World::list.push_back(this->earth);
}

void Menu::update_current(double dt)
{
    handle_input();
    handle_graphics();
}

void Menu::handle_graphics()
{
   switch(state) 
   {
        default: break;
        case State::PLAY:
            this->texture = ResourceManager::get_texture("menu_play")->get_ptr();
            break;

        case State::EXIT:
            this->texture = ResourceManager::get_texture("menu_exit")->get_ptr();
            break;
   }
}

void Menu::handle_input()
{
    switch(Keyboard::get_key())     
    {
        default: break;

        case KEY_UP:
            this->decrement_state();
            break;

        case KEY_DOWN:
            this->increment_state();
            break;
        
        case KEY_ESCAPE:
            state = State::EXIT;
            break;

        case KEY_RETURN:
            if(state == State::PLAY)
            {
                EventManager::set_event(FADE_IN_EVENT);
            }
            if(state == State::EXIT)
            {
                EventManager::set_event(CLOSE);
            }
            break;
    }
}

void Menu::decrement_state()
{
    switch(state)
    {
        default: break;

        case State::PLAY:
            state = State::EXIT;
            break;

        case State::EXIT:
            state = State::PLAY;
            break;
    }
}

void Menu::increment_state()
{
    switch(state)
    {
        default: break;

        case State::PLAY:
            state = State::EXIT;
            break;

        case State::EXIT:
            state = State::PLAY;
            break;
    }
}
