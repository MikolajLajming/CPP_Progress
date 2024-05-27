#include "main.hpp"

std::random_device random_d;
std::mt19937 mersienne_twister_engine(random_d());
std::uniform_int_distribution<> distrib(1, 20);


int main(){

    std::cout << "Hello! Welcome to the great <<OWLS VS WASPS>> simulator!" << std::endl;

    bool which_army_first{ask_who_will_go_first()};

    unsigned int first_army_size{ask_for_amount_of_entities(which_army_first)};
    std::vector<Entity>* first_army{assemble_entities_army(first_army_size, which_army_first)};

    unsigned int second_army_size{ask_for_amount_of_entities(!which_army_first)};
    std::vector<Entity>* second_army{assemble_entities_army(second_army_size, !which_army_first)};

    std::cout << "\nTwo armies: " << first_army_size << " " << say_type_name(which_army_first, first_army_size) << " and " 
            << second_army_size << " " << say_type_name(!which_army_first, second_army_size) << " will clash at dawn!" << std::endl;

    std::cout << "\nThe battle started!!!\n" << std::endl; 

    int first_army_soldiers_alive{(int)first_army->size()};
    int second_army_soldiers_alive{(int)second_army->size()};

    Entity* first_army_soldier_in_front{nullptr};
    first_army_soldier_in_front = &(*first_army).at(first_army_soldiers_alive-1);
    Entity* second_army_soldier_in_front{nullptr};
    second_army_soldier_in_front = &(*second_army).at(second_army_soldiers_alive-1);

    do{
        turn(first_army_soldier_in_front, first_army_soldiers_alive, second_army_soldier_in_front, second_army_soldiers_alive);
    } while(second_army_soldiers_alive>0 && first_army_soldiers_alive>0);

    unsigned int first_army_dead{(unsigned int)first_army->size() - first_army_soldiers_alive};
    unsigned int second_army_dead((unsigned int)second_army->size() - second_army_soldiers_alive);

    std::cout << first_army_dead << " " << say_type_name(which_army_first, first_army_dead) << " and " 
            << second_army_dead << " " << say_type_name(!which_army_first, second_army_dead) << " perished!" << std::endl;

    if(first_army_soldiers_alive>second_army_soldiers_alive){
        std::cout << say_type_name(which_army_first, first_army_soldiers_alive) << " WON" << std::endl;
    } else{
        std::cout << say_type_name(!which_army_first, second_army_soldiers_alive) << " WON" << std::endl;
    }
    std::cout << "Press Enter to exit...";
    std::cin.ignore();
    getchar();

    return 0;
}

bool ask_who_will_go_first(){
    bool bool_choice{false};
    int choice{0};
    do{
        std::cout << "\nWhich army should go first?" << std::endl << std::endl
        << "1. Owls" << std::endl
        << "2. Wasps" << std::endl << std::endl ;

        std::cin >> choice;
        if(choice == 1)
            bool_choice = true;
        else if(choice == 2)
            bool_choice = false;
        else {
            choice = 0;
            std::cout << "\nSomething went wrong... Try again!" << std::endl << std::endl;
        }
    } while(!(choice == 1 || choice == 2));
    
    return bool_choice;
}

unsigned int ask_for_amount_of_entities(bool type){
        unsigned int entities_amount{0};
        do{
        printf("\nPlease enter the amount of %s: ", say_type_name(type, 2).c_str());
        std::cin >> entities_amount;
        if(entities_amount > 4294967295){
            entities_amount = 0;
            std::cout << "That's an overkill... Try something less drastic" << std::endl;
        }
        else if(entities_amount < 1){
            entities_amount = 0;
            printf("\nThere must be at least ONE %s!\n", say_type_name(type, 1).c_str());
        }
        else if(entities_amount > 0)
            break;
        else{
            entities_amount = 0;
            std::cout << "WTH Happened? Try again pls" << std::endl;
        }
    } while(!(entities_amount>0));

    return entities_amount;
}

std::vector<Entity>* assemble_entities_army(unsigned int amount_of_entities, bool choice){
    std::vector<Entity>* army = new std::vector<Entity>;
    for(unsigned int i{amount_of_entities}; i > 0; --i){
        (*army).push_back(Entity(i, choice));
    }
    return army;
};

std::string say_type_name(bool type, unsigned int amount){
    std::string name{""};
    if(type){
        name = "Owl";
    } else
        name = "Wasp";
    if(amount != 1)
        name.push_back('s');
    return name;
}

void turn(Entity* &first_army_soldier_in_front, int &first_army_soldiers_alive, Entity* &second_army_soldier_in_front, int &second_army_soldiers_alive){
        second_army_soldier_in_front->receive_damage(first_army_soldier_in_front->calculate_damage(first_army_soldier_in_front->entity_b_attack, distrib(mersienne_twister_engine)));
        if(second_army_soldier_in_front->check_if_alive()){
            first_army_soldier_in_front->receive_damage(second_army_soldier_in_front->calculate_damage(second_army_soldier_in_front->entity_b_attack, distrib(mersienne_twister_engine)));
            if(!first_army_soldier_in_front->check_if_alive()){
                if(first_army_soldiers_alive >= 2){
                    first_army_soldier_in_front -= 1;
                }
                --first_army_soldiers_alive;
            }
        } else if(second_army_soldiers_alive >=2 ){
            second_army_soldier_in_front -= 1;
            --second_army_soldiers_alive;
            first_army_soldier_in_front->receive_damage(second_army_soldier_in_front->calculate_damage(second_army_soldier_in_front->entity_b_attack, distrib(mersienne_twister_engine)));
            if(!first_army_soldier_in_front->check_if_alive()){
                if(first_army_soldiers_alive >= 2){
                    first_army_soldier_in_front -= 1;
                }
                --first_army_soldiers_alive;
            }
        } else
            --second_army_soldiers_alive;
}