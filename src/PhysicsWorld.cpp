#include <PhysicsWorld.hpp>

PhysicsWorld::PhysicsWorld()
{
    this->screen = SDL_CreateRGBSurface(0,WINDOW_WIDTH,WINDOW_HEIGHT,16,0,0,0,0);
}

PhysicsWorld::~PhysicsWorld()
{
    SDL_FreeSurface(this->screen);
}

void PhysicsWorld::update()
{
  this->clear();
  //  this->draw(sf::Vector2f(0,0),sf::Vector2f(10,10),0xffff);
  
  for(std::vector<std::shared_ptr<Entity>>::iterator it = World::list.begin(); it != World::list.end(); ++it)
    {
        this->draw((*it)->get_position(),(*it)->get_size(),(*it)->get_id());
        //std::cout << (*it)->get_id() << std::endl;
    }
}

void PhysicsWorld::draw_pixel(uint16_t x, uint16_t y, uint16_t color)
{
    uint16_t* pixels = (uint16_t*)this->screen->pixels;
    uint16_t *pixel = pixels+(y*WINDOW_WIDTH)+x;
    *pixel = color;
}

void PhysicsWorld::draw(sf::Vector2f position, sf::Vector2f size, uint16_t color)
{
  uint16_t x = 0, y = 0;
  for(y = position.y; y < position.y + size.y; y++)
    for(x = position.x; x < position.x + size.x; x++)
        draw_pixel(x,y,color);
}

void PhysicsWorld::draw(Renderer *renderer)
{
    renderer->draw(this->screen);
}

void PhysicsWorld::clear()
{
    SDL_FillRect(this->screen,NULL,0x000000);
}
