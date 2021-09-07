

#include <Entity.hpp>
// #include <ResourceManager.hpp>
#include <Globals.h>

uint16_t Entity::p_layer = Entity::get_random_color();

Entity::Entity(std::string name):visible(false),b_destroy(false),type(NONE)
{
    this->id = p_layer;
    this->name = name;
}

Entity::Entity(SDL_Texture *texture, sf::Vector2i size, sf::Vector2f position, sf::Vector2f direction):visible(true),b_destroy(false),type(NONE)
{
    this->sprite.x = 0;
    this->sprite.y = 0;
    this->sprite.w = size.x;
    this->sprite.h = size.y;

    this->position = position;
    this->direction = direction;

    this->texture = texture;

    this->name = "undefined";

    this->id = p_layer;

    // SDL_SetTextureAlphaMod(texture, 255);
}

uint16_t Entity::get_random_color()
{
    uint16_t r = 0;
    do{
        r = rand() % 0xffff + 1;
    }
    while(r == p_layer);

    return r;
}

void Entity::update(double dt)
{
    update_current(dt);
}

void Entity::draw(Renderer *renderer)
{
    if(visible)
    {
        SDL_Rect dstrect;
        dstrect.x = this->position.x;
        dstrect.y = this->position.y;
        dstrect.w = this->sprite.w;
        dstrect.h = this->sprite.h;

        renderer->draw(this->texture, &sprite, &dstrect);
    }
}

void Entity::set_alpha(uint8_t alpha)
{
    SDL_SetTextureAlphaMod(texture, alpha);
}


