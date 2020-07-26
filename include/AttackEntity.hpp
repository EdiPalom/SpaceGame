

#ifndef ATTACK_ENTITY_H
#define ATTACK_ENTITY_H

class AttackEntity
{
    public:
        AttackEntity();

        bool is_shooting() {return b_shoot;}
        void set_shoot(bool status) {b_shoot = status;}
    
    private:
        bool b_shoot;
};

#endif
