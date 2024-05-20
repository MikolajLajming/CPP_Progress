#include "main.hpp"

using namespace std;

int main(){

    cout << "Hello! Welcome in the great <<OWLS VS WASPS>> simulator!" << endl;

    int owls_amount{ask_for_amount_of_entities(0)};
    vector<Entity>* owls_army{assemble_entities_army(owls_amount, 0)};
    int wasps_amount{ask_for_amount_of_entities(1)};
    vector<Entity>* wasps_army{assemble_entities_army(wasps_amount, 1)};
    cout << "Who will attack first?" << endl << endl
        << "1. Owls" << endl
        << "2. Wasps" << endl << endl ;
    int choice{0};
    cin >> choice;

    cout << "The battle started!!!" << endl; 

    int owls_alive{0};
    owls_alive = (int)owls_army->size();
    int wasps_alive{0};
    wasps_alive = (int)wasps_army->size();

    Entity* owl_in_front{nullptr};
    owl_in_front = &(*owls_army).at(owls_alive-1);
    Entity* wasp_in_front{nullptr};
    wasp_in_front = &(*wasps_army).at(wasps_alive-1);


    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(1, 20);
    int owls_dead(0);
    int wasps_dead(0);
    do{
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
        for(auto c: *owls_army){
            if(c.check_if_alive())
                ++owls_alive;
        }
        wasps_alive = 0;
        for(auto c: *wasps_army){
            if(c.check_if_alive())
                ++wasps_alive;
        }
    } while(wasps_alive>0 && owls_alive>0);

    cout << owls_dead << " Owls and " << wasps_dead << " Wasps perished!" << endl;

    if(wasps_alive>owls_alive){
        cout << "WASPS WON" << endl;
    } else{
        cout << "OWLS WON!" << endl;
    }

    
    return 0;
}


int ask_for_amount_of_entities(int type){
        string type_name{"None"};
        if(type == 0)
            type_name = "Owl";
        else if(type == 1)
            type_name = "Wasp";
        int entities_amount{0};
        do{
        printf("\nPlease enter the amount of %ss: ", type_name.c_str());
        cin >> entities_amount;
        if(entities_amount > 65534){
            entities_amount = 0;
            cout << "That's an overkill... Try something less drastic" << endl;
        }
        else if(entities_amount < 1){
            entities_amount = 0;
            // cout << "There must be at least ONE Owl!" << endl;
            printf("\nThere must be at least ONE %s!\n", type_name.c_str());
        }
        else if(entities_amount > 0){
            if(entities_amount == 1)
                // cout << "Nice! A single brave Owl will strike at the enemy at dawn!" << endl;
                printf("\nNice! A single brave %s will clash with the enemy at dawn!\n", type_name.c_str());
            else 
                // cout << "Nice! An army of " << entities_amount << " Owls will strike at the enemy at dawn!" << endl;
                printf("\nNice! An army of %i %ss will clash with the enemy at dawn!\n", entities_amount, type_name.c_str());
        }
        else{
            entities_amount = 0;
            cout << "WTH Happened? Try again pls" << endl;
        }
    } while(!(entities_amount>0));
    return entities_amount;
}

std::vector<Entity>* assemble_entities_army(int amount_of_entities, int entity_type){
    std::vector<Entity>* army = new std::vector<Entity>;
    for(int i{amount_of_entities}; i > 0; --i){
        Entity* new_entity = new Entity(i, entity_type);
        (*army).push_back(*new_entity);
    }
    // (*((*army).back())).die();
    
    return army;
};