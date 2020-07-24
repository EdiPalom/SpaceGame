

#ifndef FADE_IN
#define FADE_IN

#include <Entity.hpp>
#include <EventManager.hpp>

class FadeIn:public Entity
{
    public: 
        FadeIn(int limit);

        void update_current(double dt) override;

    private:
        double time;
        int life_time;
};

#endif
