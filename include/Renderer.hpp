

#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <Globals.h>

class Renderer
{
    public:
        Renderer(SDL_Window *window);
        ~Renderer();

        void clear();
        void present();
        void draw(SDL_Texture* texture, const SDL_Rect* srcrect, const SDL_Rect* dstrect);

        void draw(SDL_Surface*);

        SDL_Renderer *renderer;
        
    private:
    SDL_Texture *texture;

};

#endif
