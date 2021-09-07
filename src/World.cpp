

#include <World.hpp>

std::vector<std::shared_ptr<Entity>> World::root;
std::vector<std::shared_ptr<Entity>> World::layer1;
std::vector<std::shared_ptr<Entity>> World::list;
std::vector<std::shared_ptr<Entity>> World::utils;

void World::free_memory()
{
    World::root.clear();
    World::layer1.clear();
    World::list.clear();
    World::utils.clear();
}

void World::set_alpha(uint8_t alpha)
{
    for(long unsigned int i = 0; i < World::root.size(); ++i)
    {
        if(!World::root[i])continue;

        World::root[i]->set_alpha(alpha);
    }

    //segmentation fault
    for(std::vector<std::shared_ptr<Entity>>::iterator it = World::list.begin(); it!= World::list.end(); ++it )
    {
        (*it)->set_alpha(alpha);
        // std::cout << (*it)->get_type() << std::endl;
    }
    
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

void World::update(double dt)
{
    World::remove_entities();
    
    for(long unsigned int i = 0; i < World::utils.size(); ++i)
    {
        if(!World::utils[i]) continue;
        World::utils[i]->update(dt);
    }

    for(long unsigned int i = 0; i < World::root.size(); ++i)
    {
        if(!World::root[i]) continue;
        World::root[i]->update(dt);
    }
    
    for(long unsigned int i = 0; i < World::layer1.size(); ++i)
    {
        if(!World::layer1[i]) continue;
        World::layer1[i]->update(dt);
    }

    for(long unsigned int i = 0; i < World::list.size(); ++i)
    {
        if(!World::list[i]) continue;
        World::list[i]->update(dt);
    }
}

void World::draw(Renderer *renderer)
{
    for(long unsigned int i = 0; i < World::root.size(); ++i)
    {
      if(!World::root[i]) continue;
      World::root[i]->draw(renderer);
    }

    for(long unsigned int i = 0; i < World::layer1.size(); ++i)
    {
      if(!World::layer1[i]) continue;
      World::layer1[i]->draw(renderer);
    }    

    for(long unsigned int i = 0; i < World::list.size(); ++i)
    {
        if(!World::list[i]) continue;
        World::list[i]->draw(renderer);
    }   
}

void World::remove_entities()
{
    std::vector<std::shared_ptr<Entity>>::iterator it = World::list.begin();
    while(it != World::list.end())
    {
        if((*it)->get_destroy()) 
        {
            World::list.erase(it);
        }else
        {
            ++it;
        }
    }

    it = World::utils.begin();
    while(it != World::utils.end())
    {
        if((*it)->get_destroy()) 
        {
            World::utils.erase(it);
        }else
        {
            ++it;
        }
    }
}
