#include "main.hpp"

std::random_device random_d;
std::mt19937 mersienne_twister_engine(random_d());
std::uniform_int_distribution<> distrib(1, 20);

// I probably could do better by turning a Battle into a class, but it's good enough as for the first time

int main(){

    // The preparations

    std::cout << "Hello! Welcome to the great <<OWLS VS WASPS>> simulator!" << std::endl;

    bool which_army_first{ask_who_will_go_first()};

    unsigned int first_army_size{ask_for_amount_of_entities(which_army_first)};
    std::vector<Entity*> first_army;
    for(unsigned int i{first_army_size}; i > 0; --i){
        Entity* soldier(new Entity(i, which_army_first));
        first_army.push_back(soldier);
    }

    unsigned int second_army_size{ask_for_amount_of_entities(!which_army_first)};
    std::vector<Entity*> second_army;
    for(unsigned int i{second_army_size}; i > 0; --i){
        Entity* soldier(new Entity(i, !which_army_first));
        second_army.push_back(soldier);
    }

    std::string first_army_name = say_type_name(which_army_first, first_army_size);
    std::string second_army_name = say_type_name(!which_army_first, second_army_size);

    std::cout << "\nTwo armies: " << first_army_size << " " << first_army_name << " and " 
            << second_army_size << " " << second_army_name << " will clash at dawn!" << std::endl;

    // The Battle

    std::cout << "\nThe battle started!!!\n" << std::endl;

    do{
        turn(first_army, second_army);
    } while(first_army.size() > 0 && second_army.size() > 0);

    // Aftermath

    int first_army_soldiers_alive{(int)first_army.size()};
    int second_army_soldiers_alive{(int)second_army.size()};

    unsigned int first_army_dead{first_army_size - first_army_soldiers_alive};
    unsigned int second_army_dead(second_army_size - second_army_soldiers_alive);

    std::cout << first_army_dead << " " << first_army_name << " and " 
            << second_army_dead << " " << second_army_name << " perished!" << std::endl;

    if(first_army_soldiers_alive>second_army_soldiers_alive){
        std::cout << first_army_name << " WON" << std::endl;
    } else{
        std::cout << second_army_name << " WON" << std::endl;
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
        std::cout << "\nWhich army should attack the enemy first?" << std::endl << std::endl
        << "1. Owls" << std::endl
        << "2. Wasps" << std::endl << std::endl ;

        std::cin >> choice;
        if(choice == 1)
            bool_choice = true;
        else if(choice == 2)
            break;
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

void turn(std::vector<Entity*> &first_army, std::vector<Entity*> &second_army){
        second_army.back()->receive_damage(first_army.back()->calculate_damage(distrib(mersienne_twister_engine)));
        if(second_army.back()->check_if_alive()){
            first_army.back()->receive_damage(second_army.back()->calculate_damage(distrib(mersienne_twister_engine)));
            if(!first_army.back()->check_if_alive() && first_army.size() > 0){
                delete first_army.back();
                first_army.pop_back();
            }
        } else if(second_army.size() > 1 ){
            delete second_army.back();
            second_army.pop_back();
            first_army.back()->receive_damage(second_army.back()->calculate_damage(distrib(mersienne_twister_engine)));
            if(!first_army.back()->check_if_alive() && first_army.size() > 0){
                    delete first_army.back();
                    first_army.pop_back();
            }
        } else
            {
                delete second_army.back();
                second_army.pop_back();
            }


}