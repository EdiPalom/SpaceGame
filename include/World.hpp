

#ifndef WORLD_H
#define WORLD_H 

#include <vector>
#include <memory>

#include <Entity.hpp>
#include <Renderer.hpp>

class World
{
    public:
        static std::vector<std::shared_ptr<Entity>> root;
        static std::vector<std::shared_ptr<Entity>> layer1;    
        static std::vector<std::shared_ptr<Entity>> list;
        static std::vector<std::shared_ptr<Entity>> utils;

        static void free_memory();
        static void set_alpha(uint8_t alpha);
    static void update(double);
    static void draw(Renderer*);
    static void remove_entities();
};

#endif
