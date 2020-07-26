
#include <Running.hpp>

Running::Running():Entity(ResourceManager::get_texture("background")->get_ptr())
{
    // this->visible = false; 
    Background slow("back_small", BACK_SLOW_SPEED);
    Background medium("back_medium", BACK_MEDIUM_SPEED);
    Background fast("back_big", BACK_FAST_SPEED);
}
