#include <string>
#include <iostream>
#ifndef ENTITY_HPP
#define ENTITY_HPP
class Entity{

    private:
        uint16_t        entity_id;
        uint16_t        entity_type;
        uint16_t        entity_hp;
        uint16_t        entity_b_attack;
        bool            alive;
        
        std::string     entity_name;
    
    public:
        Entity(uint16_t id, uint16_t type);
        ~Entity();
        uint16_t attack(int dice_roll);
        void receive_damage(uint16_t attack);
        bool check_if_alive();
        void die();
};
#endif