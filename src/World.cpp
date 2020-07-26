

#include <World.hpp>

std::vector<std::shared_ptr<Entity>> World::root;
std::vector<std::shared_ptr<Entity>> World::list;

void World::free_memory()
{
    World::root.clear();
    World::list.clear();
}

void World::set_alpha(uint8_t alpha)
{
    for(long unsigned int i = 0; i < World::root.size(); ++i)
    {
        if(!World::root[i])continue;

        World::root[i]->set_alpha(alpha);
    }

    //segmentation fault
    
    // std::vector<std::shared_ptr<Entity>>::iterator it;
    //
    // for(it = World::list.begin(); it != World::list.end(); ++it)
    //     (*it)->set_alpha(alpha);
    //
    // for(long unsigned int i = 0; i < World::list.size(); ++i)
    // {
    //     if(!World::list[i])continue;
    //     World::list[i]->set_alpha(alpha);
    // }
}

