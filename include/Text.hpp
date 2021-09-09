#ifndef TEXT_H
#define TEXT_H

#include <string>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_ttf.h>

#include <Renderer.hpp>

class Text
{
public:
    Text(std::string,SDL_Rect,TTF_Font*,SDL_Renderer *);
    ~Text();

    void draw(Renderer *);
    void update(SDL_Renderer*,std::string);
private:
    std::string s_text;
    SDL_Rect d_text;
    SDL_Surface *text_surface;
    SDL_Texture *text_texture;
    SDL_Color color;
    TTF_Font *m_font;
};

#endif
