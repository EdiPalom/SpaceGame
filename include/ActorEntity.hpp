

#ifndef ACTOR_ENTITY_H
#define ACTOR_ENTITY_H

#include <memory>
#include <map>

#include <Entity.hpp>
#include <EntityComponent.hpp>

class ActorEntity: public Entity
{
    public:
        ActorEntity(SDL_Texture *texture, sf::Vector2i size, sf::Vector2f position, sf::Vector2f direction = sf::Vector2f(0,0));
        
        void update_current(double dt) override;
    //    void set_collision(bool c) override;

        void add_component(const std::shared_ptr<EntityComponent>&);

        std::weak_ptr<EntityComponent> get_component(std::string type) const;

    protected:


    private:

        std::map<std::string, std::shared_ptr<EntityComponent>> components;



};

#endif
