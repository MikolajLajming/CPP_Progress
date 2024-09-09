#include "entity.hpp"

Entity::Entity(uint32_t id, bool choice) 
    :   entity_id{new uint32_t{id}},
        entity_type{new bool{choice}},
        entity_b_attack{nullptr},
        // entity_name{nullptr},
        entity_hp{nullptr},
        alive{new bool{true}}
    {
        if(choice){
        entity_b_attack = new int{27};
        // entity_name = new std::string{"Owl_" + std::to_string(*entity_id)};
        entity_hp = new int{155};
        }
        else if(!choice){
        entity_b_attack = new int{11};
        // entity_name = new std::string{"Wasp_" + std::to_string(*entity_id)};
        entity_hp = new int{112};                                                     
        }
        // std::cout << "Constructor used" << std::endl;
    };

Entity::Entity(const Entity &source) 
    :   Entity(*source.entity_id, *source.entity_type)
    {
        alive = new bool{*source.alive};
        entity_hp = new int{*source.entity_hp};
        entity_b_attack = new int{*source.entity_b_attack};
        // entity_name = new std::string{*source.entity_name};
        // std::cout << "Copy constructor used" << std::endl;
    }

Entity::Entity(Entity &&source) noexcept
    :   entity_id{source.entity_id}, 
        entity_type{source.entity_type}, 
        alive{new bool(*source.alive)}, 
        entity_hp{new int(*source.entity_hp)},
        entity_b_attack{new int(*source.entity_b_attack)}
        // entity_name{new std::string{*source.entity_name}}
    {
        source.entity_id = nullptr;
        source.entity_type = nullptr;
        source.alive = nullptr;
        source.entity_hp = nullptr;
        source.entity_b_attack = nullptr;
        // source.entity_name = nullptr;
        // std::cout << "Move constructor used" << std::endl;
}

Entity::~Entity(){
    delete entity_id;
    delete entity_type;
    delete entity_hp;
    delete alive;
    delete entity_b_attack;
    // delete entity_name;
    // std::cout << "Destructor used" << std::endl;
};

void Entity::receive_damage(int damage){
    if(*entity_hp <= damage) {
        die();
    } else
        *entity_hp -= damage;      
}

bool Entity::check_if_alive() const{
    return *alive;
}

void Entity::die(){
    *entity_hp = 0;
    *alive = false;
    // if(*entity_type)
    //     std::cout << "Owl fucking dies!!!" << std::endl;
    // else
    //     std::cout << "Wasp fucking dies!!!" << std::endl;
};

int Entity::calculate_damage(int dice_roll) const {
    if(dice_roll == 1)
        return 0;
    else if(dice_roll == 2)
        return *entity_b_attack / 2;
    else if(dice_roll <= 4)
        return *entity_b_attack - 2;
    else if(dice_roll < 7)
        return *entity_b_attack - 1;
    else if(dice_roll < 14)
        return *entity_b_attack;
    else if(dice_roll < 17)
        return *entity_b_attack + 1;
    else if(dice_roll <= 19)
        return *entity_b_attack + 2;
    else if(dice_roll == 20)
        return *entity_b_attack * 2;
    else 
        return 0;
}
