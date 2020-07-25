

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
    SDL_SetRenderDrawColor(created, 10, 10, 10, 0);
    SDL_RenderClear(created);
}

void Renderer::present()
{
    SDL_RenderPresent(created);
}

void Renderer::draw(SDL_Texture *texture, const SDL_Rect* srcrect, const SDL_Rect* dstrect)
{
    SDL_RenderCopy(created, texture, srcrect, dstrect);
}
