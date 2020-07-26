#include <ActorEntity.hpp>

ActorEntity::ActorEntity(SDL_Texture *texture, sf::Vector2i size, sf::Vector2f position, sf::Vector2f direction):Entity(texture,size,position,direction)
{

}

void ActorEntity::update_current(double dt)
{
    if(!components.empty())
    {
        std::map<std::string, std::shared_ptr<EntityComponent>>::iterator it = components.begin();
        while (it != components.end())
        {
            it->second->update(*this, dt);
            ++it;
        }
    }
}

void ActorEntity::add_component(const std::shared_ptr<EntityComponent>& component)
{
    components[component->s_type] = component;
}

std::weak_ptr <EntityComponent> ActorEntity::get_component(std::string type) const
{
    auto it = components.find(type);

    if(it != components.end())
    {
        std::weak_ptr<EntityComponent> component(it->second);
        return component;
    }else
        return std::weak_ptr<EntityComponent>{};
}
