#include "entity.hpp"
#include <random>
#include <vector>

bool ask_who_will_go_first();
unsigned int ask_for_amount_of_entities(bool type);
std::string say_type_name(bool type, unsigned int amount);
void turn(std::vector<Entity*> &first_army, std::vector<Entity*> &second_army);