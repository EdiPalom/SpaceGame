

#ifndef ATTACK_ENTITY_H
#define ATTACK_ENTITY_H

#include <cstdint>

class AttackEntity
{
    public:
        AttackEntity();
        AttackEntity(uint8_t);

        bool is_shooting() {return b_shoot;}
        void set_shoot(bool status) {b_shoot = status;}
        uint8_t get_position(){return this->m_position;}
    
    private:
        bool b_shoot;
        uint8_t m_position;
};

#endif
