

#include <World.hpp>

std::vector<std::shared_ptr<Entity>> World::root;
std::vector<std::shared_ptr<Entity>> World::list;

void World::free_memory()
{
    World::root.clear();
    World::list.clear();
}

