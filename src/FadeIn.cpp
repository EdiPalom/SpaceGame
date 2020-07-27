

#include <FadeIn.hpp>
#include <ResourceManager.hpp>

// FadeIn::FadeIn(int limit):Entity(ResourceManager::get_texture("menu")->get_ptr()),time(0),life_time(limit)
FadeIn::FadeIn(int limit):Entity("fade_in"),time(0),life_time(limit)
{
    alpha = 255;
    time = 0;
    mod_alpha = life_time / alpha;
    counter_time = 0;
    life_time = limit;
    counter = 0;
}

void FadeIn::update_current(double dt)
{
    if(time < life_time)
    {
        time += dt;

        if(alpha != 0)
            alpha -= 5;
            
        World::set_alpha(alpha);

    }else
    {
        EventManager::set_event(CHANGE_SCENE);

        World::set_alpha(255);
        this->b_destroy = true;
    }
}
