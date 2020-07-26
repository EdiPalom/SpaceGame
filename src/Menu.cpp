

#include <Menu.hpp>

Menu::Menu():Entity(ResourceManager::get_texture("menu_play")->get_ptr())
{
    
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
