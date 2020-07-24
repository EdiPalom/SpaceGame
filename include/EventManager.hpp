

#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <queue>
#include <GameEvents.h>

class EventManager
{
    public:
        static std::queue<int> event;
        static int get_event();
        static bool request_event(int e);
        static void set_event(int);
        static void print();
};

#endif
