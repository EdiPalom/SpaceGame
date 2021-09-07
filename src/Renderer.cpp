

#include <Renderer.hpp>

Renderer::Renderer(SDL_Window *window)
{
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    this->texture = SDL_CreateTexture(this->renderer,SDL_PIXELFORMAT_RGB565,SDL_TEXTUREACCESS_STREAMING,WINDOW_WIDTH,WINDOW_HEIGHT);
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(renderer);
}

void Renderer::clear()
{
    // SDL_SetRenderDrawColor(renderer, 10, 10, 10, 0);
    SDL_SetRenderDrawColor(renderer, 10, 10, 10, 0);
    SDL_RenderClear(renderer);
}

void Renderer::present()
{
    SDL_RenderPresent(renderer);
}

void Renderer::draw(SDL_Texture *texture, const SDL_Rect* srcrect, const SDL_Rect* dstrect)
{
    SDL_RenderCopy(renderer, texture, srcrect, dstrect);
}

void Renderer::draw(SDL_Surface* surface)
{
    SDL_UpdateTexture(this->texture,NULL,surface->pixels,WINDOW_WIDTH*sizeof(uint16_t));

    SDL_RenderCopy(renderer,this->texture,NULL,NULL);
}
