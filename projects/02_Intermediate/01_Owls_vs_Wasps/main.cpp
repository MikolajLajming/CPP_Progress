#include "main.hpp"

int main(){

    std::cout << "Hello! Welcome in the great <<OWLS VS WASPS>> simulator!" << std::endl;

//TODO: Use input to determine type AND order of armies, getting rid of the awful "choice" variable
//Something like: "Which army should go first?" and then construct first and second army

    int owls_amount{ask_for_amount_of_entities(0)};
    std::vector<Entity>* owls_army{assemble_entities_army(owls_amount, 0)};
    int wasps_amount{ask_for_amount_of_entities(1)};
    std::vector<Entity>* wasps_army{assemble_entities_army(wasps_amount, 1)};
    std::cout << "Who will attack first?" << std::endl << std::endl
        << "1. Owls" << std::endl
        << "2. Wasps" << std::endl << std::endl ;
    int choice{0};
    std::cin >> choice;

    std::cout << "The battle started!!!" << std::endl; 

    int owls_alive{0};
    owls_alive = (int)owls_army->size();
    int wasps_alive{0};
    wasps_alive = (int)wasps_army->size();

    Entity* owl_in_front{nullptr};
    owl_in_front = &(*owls_army).at(owls_alive-1);
    Entity* wasp_in_front{nullptr};
    wasp_in_front = &(*wasps_army).at(wasps_alive-1);

//TODO: throw this all in functions, maybe even screate a class with methods /

    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(1, 20);
    int owls_dead(0);
    int wasps_dead(0);
    do{
        // std::cout << "\nNew round starts\n" << std::endl;
        if(choice == 1){
            wasp_in_front->receive_damage(owl_in_front->attack(distrib(gen)));
            if(wasp_in_front->check_if_alive()){
                owl_in_front->receive_damage(wasp_in_front->attack(distrib(gen)));
                if(!owl_in_front->check_if_alive()){
                    if(owls_alive >= 2){
                        owl_in_front -= 1;
                    }
                    ++owls_dead;
                }
            } else if(wasps_alive >=2 ){
                wasp_in_front -= 1;
                ++wasps_dead;
                owl_in_front->receive_damage(wasp_in_front->attack(distrib(gen)));
                if(!owl_in_front->check_if_alive()){
                    if(owls_alive >= 2){
                        owl_in_front -= 1;
                    }
                    ++owls_dead;
                }
            } else
                ++wasps_dead;
        } else if(choice == 2){
            owl_in_front->receive_damage(wasp_in_front->attack(distrib(gen)));
            if(owl_in_front->check_if_alive()){
                wasp_in_front->receive_damage(owl_in_front->attack(distrib(gen)));
                if(!wasp_in_front->check_if_alive()){
                    if(wasps_alive >=2 ){
                        wasp_in_front -= 1;
                    }
                    ++wasps_dead;
                }
            } else if(owls_alive >=2 ){
                owl_in_front -= 1;
                ++owls_dead;
                wasp_in_front->receive_damage(owl_in_front->attack(distrib(gen)));
                if(!wasp_in_front->check_if_alive()){
                    if(wasps_alive >=2 ){
                        wasp_in_front -= 1;
                    }                    
                    ++wasps_dead;
                }
            } else
                ++owls_dead;
        }

        owls_alive = 0;
        for(auto &c: *owls_army){
            if(c.check_if_alive())
                ++owls_alive;
        }
        wasps_alive = 0;
        for(auto &c: *wasps_army){
            if(c.check_if_alive())
                ++wasps_alive;
        }
    } while(wasps_alive>0 && owls_alive>0);

    //TODO: throw this all in functions, maybe even screate a class with methods /

    std::cout << owls_dead << " Owls and " << wasps_dead << " Wasps perished!" << std::endl;

    if(wasps_alive>owls_alive){
        std::cout << "WASPS WON" << std::endl;
    } else{
        std::cout << "OWLS WON!" << std::endl;
    }
    std::cout << "Press Enter to exit...";
    std::cin.ignore();
    getchar();

    return 0;
}


int ask_for_amount_of_entities(int type){
        std::string type_name{"None"};
        if(type == 0)
            type_name = "Owl";
        else if(type == 1)
            type_name = "Wasp";
        int entities_amount{0};
        do{
        printf("\nPlease enter the amount of %ss: ", type_name.c_str());
        std::cin >> entities_amount;
        if(entities_amount > 65534){
            entities_amount = 0;
            std::cout << "That's an overkill... Try something less drastic" << std::endl;
        }
        else if(entities_amount < 1){
            entities_amount = 0;
            printf("\nThere must be at least ONE %s!\n", type_name.c_str());
        }
        else if(entities_amount > 0){
            if(entities_amount == 1)
                printf("\nNice! A single brave %s will clash with the enemy at dawn!\n", type_name.c_str());
            else 
                printf("\nNice! An army of %i %ss will clash with the enemy at dawn!\n", entities_amount, type_name.c_str());
        }
        else{
            entities_amount = 0;
            std::cout << "WTH Happened? Try again pls" << std::endl;
        }
    } while(!(entities_amount>0));
    return entities_amount;
}

std::vector<Entity>* assemble_entities_army(int amount_of_entities, int entity_type){
    std::vector<Entity>* army = new std::vector<Entity>;
    for(int i{amount_of_entities}; i > 0; --i){
        Entity* new_entity = new Entity(i, entity_type);
        (*army).push_back(*new_entity);
        delete new_entity;
    }
    
    return army;
};