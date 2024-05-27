#include "entity.hpp"
#include <random>
#include <vector>

bool ask_who_will_go_first();
unsigned int ask_for_amount_of_entities(bool type);
std::vector<Entity>* assemble_entities_army(unsigned int amount_of_entities, bool entity_type);
std::string say_type_name(bool type, unsigned int amount);
void turn(Entity* &first_army_soldier_in_front, int &first_army_soldiers_alive, Entity* &second_army_soldier_in_front, int &second_army_soldiers_alive);