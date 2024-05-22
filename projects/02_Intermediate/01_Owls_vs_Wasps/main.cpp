#include "main.hpp"

int main(){

    std::cout << "Hello! Welcome to the great <<OWLS VS WASPS>> simulator!" << std::endl;

//TODO: Use input to determine type AND order of armies, getting rid of the awful "choice" variable
//Something like: "Which army should go first?" and then construct first and second army

    unsigned int owls_amount{ask_for_amount_of_entities(1)};
    std::vector<Entity>* first_army{assemble_entities_army(owls_amount, 1)};
    unsigned int wasps_amount{ask_for_amount_of_entities(2)};
    std::vector<Entity>* second_army{assemble_entities_army(wasps_amount, 2)};
    
    std::cout << "Which army should go first?" << std::endl << std::endl
    << "1. Owls" << std::endl
    << "2. Wasps" << std::endl << std::endl ;
    int choice{0};
    std::cin >> choice;

    std::cout << "The battle started!!!" << std::endl; 

    int owls_alive{0};
    owls_alive = (int)first_army->size();
    int wasps_alive{0};
    wasps_alive = (int)second_army->size();

    Entity* owl_in_front{nullptr};
    owl_in_front = &(*first_army).at(owls_alive-1);
    Entity* wasp_in_front{nullptr};
    wasp_in_front = &(*second_army).at(wasps_alive-1);

//TODO: throw this all in functions, maybe even screate a class with methods /

    std::random_device random_d;
    std::mt19937 mersienne_twister_engine(random_d());
    std::uniform_int_distribution<> distrib(1, 20);
    do{
        if(choice == 1){
            wasp_in_front->receive_damage(owl_in_front->attack(distrib(mersienne_twister_engine)));
            if(wasp_in_front->check_if_alive()){
                owl_in_front->receive_damage(wasp_in_front->attack(distrib(mersienne_twister_engine)));
                if(!owl_in_front->check_if_alive()){
                    if(owls_alive >= 2){
                        owl_in_front -= 1;
                    }
                    --owls_alive;
                }
            } else if(wasps_alive >=2 ){
                wasp_in_front -= 1;
                --wasps_alive;
                owl_in_front->receive_damage(wasp_in_front->attack(distrib(mersienne_twister_engine)));
                if(!owl_in_front->check_if_alive()){
                    if(owls_alive >= 2){
                        owl_in_front -= 1;
                    }
                    --owls_alive;
                }
            } else
                --wasps_alive;
        } else if(choice == 2){
            owl_in_front->receive_damage(wasp_in_front->attack(distrib(mersienne_twister_engine)));
            if(owl_in_front->check_if_alive()){
                wasp_in_front->receive_damage(owl_in_front->attack(distrib(mersienne_twister_engine)));
                if(!wasp_in_front->check_if_alive()){
                    if(wasps_alive >=2 ){
                        wasp_in_front -= 1;
                    }
                    --wasps_alive;
                }
            } else if(owls_alive >=2 ){
                owl_in_front -= 1;
                --owls_alive;
                wasp_in_front->receive_damage(owl_in_front->attack(distrib(mersienne_twister_engine)));
                if(!wasp_in_front->check_if_alive()){
                    if(wasps_alive >=2 ){
                        wasp_in_front -= 1;
                    }                    
                    --wasps_alive;
                }
            } else
                --owls_alive;
        }
    } while(wasps_alive>0 && owls_alive>0);

    //TODO: throw this all in functions, maybe even screate a class with methods /

    std::cout << (int)first_army->size() - owls_alive << " Owls and " << (int)second_army->size() - wasps_alive << " Wasps perished!" << std::endl;

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


unsigned int ask_for_amount_of_entities(int type){
        std::string type_name{"None"};
        if(type == 1)
            type_name = "Owl";
        else if(type == 2)
            type_name = "Wasp";
        unsigned int entities_amount{0};
        do{
        printf("\nPlease enter the amount of %ss: ", type_name.c_str());
        std::cin >> entities_amount;
        if(entities_amount > 4294967295){
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

std::vector<Entity>* assemble_entities_army(unsigned int amount_of_entities, int entity_type){
    std::vector<Entity>* army = new std::vector<Entity>;
    for(unsigned int i{amount_of_entities}; i > 0; --i){
        (*army).push_back(Entity(i, entity_type));
    }
    
    return army;
};