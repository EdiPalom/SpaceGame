
#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL_ttf.h>

#include <StateMachine.hpp>
#include <World.hpp>
#include <EventManager.hpp>
#include <PhysicsWorld.hpp>
#include <Text.hpp>

class Game
{
    public:
        Game(Renderer *);
        ~Game();

        bool initialize();
        void update(double dt);
        void draw(Renderer *);
        bool is_active(){return active;}
        void remove_entities();

    private:
        StateMachine state_machine;
        bool active;
        PhysicsWorld physics;
        TTF_Font *font;
        Text *score;
        Text *counter;
        int count;

    Renderer* renderer;
};

#endif
