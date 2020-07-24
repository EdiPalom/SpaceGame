

#include <EventManager.hpp>
#include <iostream>

std::queue<int> EventManager::event;

void EventManager::set_event(int e)
{
    EventManager::event.push(e);
}

bool EventManager::request_event(int e)
{
    if(EventManager::event.front() == e) 
    {
        EventManager::event.pop();
        return true;
    }

    return false;

}

int EventManager::get_event()
{
    if(!EventManager::event.empty())
    {
        int e = EventManager::event.front();
        EventManager::event.pop();
        return e;
    }
    return -1;
}

void EventManager::print()
{
    std::cout << EventManager::event.front() << std::endl;
}
