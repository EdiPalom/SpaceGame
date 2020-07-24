

#ifndef WORLD_H
#define WORLD_H 

#include <vector>
#include <memory>

#include <Entity.hpp>

class World
{
    public:
        static std::vector<std::shared_ptr<Entity>> list;
        static void free_memory();
};

#endif
