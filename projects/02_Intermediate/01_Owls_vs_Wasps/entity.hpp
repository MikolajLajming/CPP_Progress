#include <string>
#include <iostream>
#ifndef ENTITY_HPP
#define ENTITY_HPP
class Entity{

    private:
        const uint32_t*     entity_id;
        const uint16_t*     entity_type;
        const int*          entity_b_attack;
        // const std::string*  entity_name;
        int*                entity_hp;
        bool*               alive;

        int calculate_damage(const int* b_attack, int dice_roll) const;
        void die();
    
    public:
        Entity(uint32_t id, uint16_t type);
        Entity(const Entity &source);
        Entity(Entity &&source);
        ~Entity();
        int attack(int dice_roll) const;
        void receive_damage(int attack);
        bool check_if_alive() const;

};
#endif