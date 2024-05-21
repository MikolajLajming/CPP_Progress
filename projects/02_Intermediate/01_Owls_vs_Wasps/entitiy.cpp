#include "entity.hpp"

uint16_t calculate_damage(uint16_t b_attack, uint16_t dice_roll);
uint16_t calculate_hp(uint16_t type);
uint16_t calculate_b_attack(uint16_t type);
std::string give_name_to_entity(uint16_t type, uint16_t id);


Entity::Entity(uint16_t id, uint16_t type) : entity_id{id}, //
                                                entity_type{type},
                                                alive{true}, 
                                                entity_hp{calculate_hp(type)},
                                                entity_b_attack{calculate_b_attack(type)},
                                                entity_name{give_name_to_entity(type, id)}
                                                {};

Entity::~Entity(){
    // std::cout << entity_name << " fucking dies!" << std::endl;
    // die();
};

uint16_t Entity::attack(int dice_roll){
    // std::cout << entity_name << " says: JUST DIE ALREADY!" << std::endl;
    return calculate_damage(entity_b_attack, dice_roll);
}

void Entity::receive_damage(uint16_t damage){
    if(entity_hp <= damage) {
        die();
    } else
        entity_hp -= damage;        
}

bool Entity::check_if_alive(){
    return alive;
}

void Entity::die(){
    entity_hp = 0;
    alive = false;
    // if(entity_type == 0)
    //     std::cout << "Owl no." << entity_id << " is dying! Aghrrrhrh! " << std::endl;
    // else if(entity_type == 1)
    //     std::cout << "Wasp no." << entity_id << " is dying! Bzzrrghrghzz! " << std::endl;
    // Entity::~Entity();
};

uint16_t calculate_damage(uint16_t b_attack, uint16_t dice_roll){
    if(dice_roll == 1)
        return 0;
    else if(dice_roll < 4)
        return (b_attack - 2);
    else if(dice_roll < 7)
        return (b_attack - 1);
    else if(dice_roll < 14)
        return b_attack;
    else if(dice_roll < 17)
        return (b_attack + 1);
    else if(dice_roll < 19)
        return (b_attack + 2);
    else if(dice_roll == 20)
        return (b_attack * 2);
    else 
        return 0;
}

uint16_t calculate_hp(uint16_t type){
    if(type == 0)
        return 150;
    else if(type == 1)
        return 120;
    else
        return 0;
}

uint16_t calculate_b_attack(uint16_t type){
    if(type == 0)
        return 30;
    else if(type == 1)
        return 10;
    else
        return 0;
}

std::string give_name_to_entity(uint16_t type, uint16_t id){
    std::string name{"None"};
    if(type == 0){
        name = "Owl_" + std::to_string(id);
    }
    else if(type == 1){
        name = "Wasp_" + std::to_string(id);
    }
    return name;
}

