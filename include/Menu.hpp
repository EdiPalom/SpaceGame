

#ifndef MENU_H
#define MENU_H

#include <Entity.hpp>
#include <ResourceManager.hpp>
#include <Keyboard.hpp>
#include <EventManager.hpp>

class Menu:public Entity
{
    public:
       enum class State:char{
            PLAY, EXIT
       } state = State::PLAY; 

       Menu();

       void update_current(double dt) override;
       void handle_input();
       void handle_graphics();
       void increment_state();
       void decrement_state();
};

#endif
