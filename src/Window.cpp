

#include <Window.hpp>
#include <Globals.h>

Window::Window():created(nullptr)
{
    created = SDL_CreateWindow("game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT,0);
}

Window::~Window()
{
    SDL_DestroyWindow(created);
}
