#include <string>
#include <iostream>
#ifndef ENTITY_HPP
#define ENTITY_HPP
class Entity{

    private:
        uint32_t*        entity_id;
        uint16_t*        entity_type;
        int*        entity_hp;
        int*             entity_b_attack;
        bool*            alive;
        std::string*     entity_name;

        int* calculate_hp(uint16_t type);
        int* calculate_b_attack(uint16_t type);
        std::string* give_name_to_entity(uint16_t type, uint32_t id);
        int calculate_damage(int* b_attack, int dice_roll);
    
    public:
        Entity(uint32_t id, uint16_t type);
        Entity(const Entity &source);
        Entity(Entity &&source);
        ~Entity();
        int attack(int dice_roll);
        void receive_damage(int attack);
        bool check_if_alive();
        void die();
};
#endif