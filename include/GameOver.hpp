#ifndef GAME_OVER
#define GAME_OVER

#include <Entity.hpp>
#include <World.hpp>
#include <ResourceManager.hpp>
#include <Timer.hpp>
#include <EventManager.hpp>

class GameOver:public Entity
{
public:
    GameOver();

    virtual void update_current(double) override;
    virtual void set_collision(bool) override;

private:
    Timer m_timer;
};

#endif
