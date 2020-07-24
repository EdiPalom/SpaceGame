

#include <Renderer.hpp>

Renderer::Renderer(SDL_Window *window)
{
    created = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(created);
}

void Renderer::clear()
{
    // SDL_SetRenderDrawColor(created, 10, 10, 10, 0);
    SDL_SetRenderDrawColor(created, 255, 10, 10, 0);
    SDL_RenderClear(created);
}

void Renderer::present()
{
    SDL_RenderPresent(created);
}
