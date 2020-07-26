

#include <FadeIn.hpp>
#include <ResourceManager.hpp>

FadeIn::FadeIn(int limit):Entity(ResourceManager::get_texture("menu")->get_ptr()),time(0),life_time(limit)
{
    this->name = "Fade in";
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
