

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

        SDL_Renderer *created;

    private:

};

#endif
