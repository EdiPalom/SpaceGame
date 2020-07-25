

#include <Entity.hpp>
// #include <ResourceManager.hpp>
#include <Globals.h>

Entity::Entity(std::string name):visible(false)
{
   this->name = name;
}

Entity::Entity(SDL_Texture *texture,bool is_visible, sf::Vector2i size, sf::Vector2f position):visible(true)
{
    this->sprite.x = position.x;
    this->sprite.y = position.y;
    this->sprite.w = size.x;
    this->sprite.h = size.y;

    this->texture = texture;

    this->name = "undefined";
}

void Entity::update(double dt)
{
    update_current(dt);
    // std::cout << "Entity " <<  this->name << std::endl;
}

void Entity::draw(Renderer *renderer)
{
    // SDL_Rect dstrect;
    // dstrect.x = 0;
    // dstrect.y = 0;
    // dstrect.w = 100;
    // dstrect.x = 100;
    // dstrect.x = this->position.x;
    // dstrect.y = this->position.y;
    // // dstrect.x = this->sprite.x;
    // // dstrect.y = this->sprite.y;
    // dstrect.w = this->sprite.w;
    // dstrect.h = this->sprite.h;

    if(visible)
    {
        SDL_Rect dstrect;
        dstrect.x = 0;
        dstrect.y = 0;
        dstrect.w = WINDOW_WIDTH;
        dstrect.h = WINDOW_HEIGHT;

        // In texture coords
        // SDL_Rect strect;
        // strect.x = 0;
        // strect.y = 0;
        // strect.w = 100;
        // strect.h = 100;

        // renderer->draw(this->texture, &strect, &dstrect);
        // renderer->draw(ResourceManager::get_texture("menu"), NULL, &dstrect);
        // renderer->draw(ResourceManager::get_texture("menu"), NULL, &dstrect);
        renderer->draw(this->texture, NULL, &dstrect);

        // std::cout << this->name << " drawing" << std::endl;
    }

    // renderer->draw(this->texture,&this->sprite, &dstrect);

}


