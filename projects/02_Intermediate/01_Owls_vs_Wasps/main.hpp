#include "entity.hpp"
#include <random>
#include <vector>

unsigned int ask_for_amount_of_entities(int type);
std::vector<Entity>* assemble_entities_army(unsigned int amount_of_entities, int entity_type);
