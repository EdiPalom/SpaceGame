
#include <Game.hpp>

Game::Game()
{

}

bool Game::initialize()
{
    return true;
}

void Game::update(double dt)
{
    state_machine.process_event();
}

void Game::draw()
{

}
