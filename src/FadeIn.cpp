

#include <FadeIn.hpp>

FadeIn::FadeIn(int limit):Entity("Fade in"),time(0),life_time(limit)
{
}

void FadeIn::update_current(double dt)
{
    if(time < life_time)
    {
        time += dt;
    }else
    {
        EventManager::set_event(CHANGE_SCENE);
    }
}
