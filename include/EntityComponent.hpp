#ifndef ENTITY_COMPONENT_H
#define ENTITY_COMPONENT_H

#include <string>
#include <Renderer.hpp>
#include <Entity.hpp>

class Entity;

class EntityComponent
{
    public:
        // virtual ~EntityComponent() = default;

        virtual void update(Entity &entity,double dt) = 0;
        virtual void draw(Renderer &renderer)const {};
        virtual void start_animation(){};
        std::string s_type;

    // private:

};

#endif
