#ifndef PHYSICS_WORLD
#define PHYSICS_WORLD

#include <vector>
#include <cstdint>

#include <Globals.h>
#include <World.hpp>
#include <Vector2.hpp>

class PhysicsWorld
{
public:
  PhysicsWorld();
  ~PhysicsWorld();

  void update();
    void draw_pixel(uint16_t, uint16_t,uint16_t);
    void draw(sf::Vector2f, sf::Vector2f, uint16_t);
    void draw(Renderer*);
  void clear();
  
private:
    SDL_Surface *screen;
    SDL_Texture *texture;
};

#endif
