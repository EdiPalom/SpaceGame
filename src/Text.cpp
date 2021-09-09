#include <Text.hpp>

Text::Text(std::string text, SDL_Rect data,TTF_Font *font,SDL_Renderer *renderer)
{
    this->s_text = text;
    this->d_text = data;
    this->m_font = font;   
    this->color= {255,255,255};
    this->text_surface = TTF_RenderText_Solid(font,text.c_str(),this->color);
    //this->text_texture = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_ARGB8888,SDL_TEXTUREACCESS_STREAMING,data.w,data.h);

    //SDL_UpdateTexture(this->text_texture,NULL,this->text_surface->pixels,data.w * sizeof(Uint32));
    this->text_texture = SDL_CreateTextureFromSurface(renderer,this->text_surface);
    SDL_FreeSurface(this->text_surface);
}

Text::~Text()
{
    SDL_DestroyTexture(this->text_texture);
}

void Text::update(SDL_Renderer *renderer,std::string text)
{
    this->text_surface = TTF_RenderText_Solid(this->m_font,text.c_str(),this->color);
    //SDL_UpdateTexture(this->text_texture,NULL,this->text_surface->pixels,text_surface->pitch);
    
    this->text_texture = SDL_CreateTextureFromSurface(renderer,this->text_surface);
    SDL_FreeSurface(this->text_surface);
}

void Text::draw(Renderer *renderer)
{
    renderer->draw(this->text_texture,NULL,&d_text);
}

