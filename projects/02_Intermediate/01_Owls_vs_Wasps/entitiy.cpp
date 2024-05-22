#include "entity.hpp"

Entity::Entity(uint32_t id, uint16_t type) : entity_id{nullptr}, //
                                                entity_type{nullptr},
                                                alive{nullptr}, 
                                                entity_hp{calculate_hp(type)},
                                                entity_b_attack{calculate_b_attack(type)},
                                                entity_name{give_name_to_entity(type, id)}
                                                {
                                                    entity_id = new uint32_t{id};
                                                    entity_type = new uint16_t{type};
                                                    alive = new bool{true};
                                                };

Entity::Entity(const Entity &source) : Entity(*source.entity_id, *source.entity_type){
    alive = new bool{*source.alive};
    entity_hp = new int{*source.entity_hp};
    entity_b_attack = new int{*source.entity_b_attack};
    entity_name = new std::string{*source.entity_name};
}

Entity::Entity(Entity &&source) : entity_id{source.entity_id}, entity_type{source.entity_type}{
    source.entity_id = nullptr;
    source.entity_type = nullptr;
    alive = new bool{*source.alive};
    source.alive = nullptr;
    entity_hp = new int{*source.entity_hp};
    source.entity_hp = nullptr;
    entity_b_attack = new int{*source.entity_b_attack};
    source.entity_b_attack = nullptr;
    entity_name = new std::string{*source.entity_name};
    source.entity_name = nullptr;
}

Entity::~Entity(){
    delete entity_id;
    delete entity_type;
    delete entity_hp;
    delete alive;
    delete entity_b_attack;
    delete entity_name;
};

int Entity::attack(int dice_roll){
    return calculate_damage(entity_b_attack, dice_roll);
}

void Entity::receive_damage(int damage){
    if(*entity_hp <= damage) {
        die();
    } else
        *entity_hp -= damage;      
}

bool Entity::check_if_alive(){
    return *alive;
}

void Entity::die(){
    *entity_hp = 0;
    *alive = false;
};


int* Entity::calculate_hp(uint16_t type){
    if(type == 0){
        int* hp{nullptr};
        hp = new int{150};
        return hp;
    }
    else if(type == 1){
        int* hp{nullptr};
        hp = new int{120};
        return hp;
    }
    else
        return nullptr;
}

int* Entity::calculate_b_attack(uint16_t type){
    if(type == 0){
        int* b_attack{nullptr};
        b_attack = new int{30};
        return b_attack;
    }
    else if(type == 1){
        int* b_attack{nullptr};
        b_attack = new int{12};
        return b_attack;
    }
    else
        return nullptr;
}

std::string* Entity::give_name_to_entity(uint16_t type, uint32_t id){
    std::string* name{nullptr};
    name = new std::string{"None"};
    if(type == 0){
        *name = "Owl_" + std::to_string(id);
    }
    else if(type == 1){
        *name = "Wasp_" + std::to_string(id);
    }
    return name;
}

int Entity::calculate_damage(int* b_attack, int dice_roll){
    if(dice_roll == 1)
        return 0;
    else if(dice_roll < 4)
        return *b_attack - 2;
    else if(dice_roll < 7)
        return *b_attack - 1;
    else if(dice_roll < 14)
        return *b_attack;
    else if(dice_roll < 17)
        return *b_attack + 1;
    else if(dice_roll < 19)
        return *b_attack + 2;
    else if(dice_roll == 20)
        return *b_attack * 2;
    else 
        return 0;
}
