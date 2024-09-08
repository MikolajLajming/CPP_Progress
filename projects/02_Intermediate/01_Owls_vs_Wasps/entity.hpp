#include <string>
#include <iostream>
#ifndef ENTITY_HPP
#define ENTITY_HPP
class Entity{

    private:
        const uint32_t*     entity_id;
        const bool*         entity_type;
        // const std::string*  entity_name;
        int*                entity_hp;
        bool*               alive;
        const int*          entity_b_attack;
        void die();
    
    public:

        Entity(uint32_t id, bool choice);
        Entity(const Entity &source);
        Entity(Entity &&source) noexcept;
        ~Entity();
        int calculate_damage(int dice_roll) const;
        void receive_damage(int attack);
        bool check_if_alive() const;

};
#endif