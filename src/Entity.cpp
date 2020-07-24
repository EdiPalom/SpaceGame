

#include <Entity.hpp>

Entity::Entity(std::string name)
{
   this->name = name;
}

void Entity::update(double dt)
{
    update_current(dt);
    std::cout << "Entity " <<  this->name << std::endl;
}


