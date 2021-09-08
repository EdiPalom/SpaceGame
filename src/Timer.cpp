#include <Timer.hpp>

Timer::Timer(double s_time)
{
    this->s_time = s_time;
    this->d_time = 0;
}

Timer::~Timer()
{
    
}

bool Timer::get_signal(double dt)
{
    this->d_time += dt;
    if(this->d_time >= this->s_time)
    {
        this->d_time = 0;
        return true;
    }

    return false;
}
