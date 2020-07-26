

#ifndef WORLD_H
#define WORLD_H 

#include <vector>
#include <memory>

#include <Entity.hpp>

class World
{
    public:
        static std::vector<std::shared_ptr<Entity>> root;
        static std::vector<std::shared_ptr<Entity>> list;
        static void free_memory();
        static void set_alpha(uint8_t alpha);
};

#endif
