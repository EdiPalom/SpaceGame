

#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <iostream>

class Entity
{
    public:
        Entity(std::string name);
        void update(double dt);
        virtual void update_current(double dt){};

    private:
        std::string name;

};

#endif
