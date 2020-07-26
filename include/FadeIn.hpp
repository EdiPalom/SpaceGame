

#ifndef FADE_IN
#define FADE_IN

#include <Entity.hpp>
#include <EventManager.hpp>
#include <World.hpp>

class FadeIn:public Entity
{
    public: 
        FadeIn(int limit);

        void update_current(double dt) override;

    private:
        double time, mod_alpha, counter_time;
        int life_time, counter;
        uint8_t alpha;

};

#endif
