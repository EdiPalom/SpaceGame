

#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>


class Window
{
    public:
        Window();
        ~Window();

        SDL_Window* get_ptr(){return created;}
        SDL_Window* created;

    private:

};

#endif
