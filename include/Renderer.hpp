

#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>

class Renderer
{
    public:
        Renderer(SDL_Window *window);
        ~Renderer();

        void clear();
        void present();
        void draw(SDL_Texture* texture, const SDL_Rect* srcrect, const SDL_Rect* dstrect);

        SDL_Renderer *created;
        

    private:

};

#endif
