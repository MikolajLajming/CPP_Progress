#include "main.h"

int main() 
{ 
    std::cout << "Hello, simple something here. We're gonna ask you to enter some integers and we'll put them into a list you can iteract with." << std::endl;
    int number_of_integers{0};

    std::cout << "How many items in the list do you want to enter?: ";
    std::cin >> number_of_integers;

    std::vector<int> items{};
    int temp{0};

    if(number_of_integers > 0){
        for(int i{1}; i <= number_of_integers; ++i){
            std::cout << "Please enter item no " << i << ": ";
            std::cin >> temp;
            items.push_back(temp);
        }
        temp = 0;
        number_of_integers = 0;
    }
    
    char selection{0};
    double mean{0.0};
    bool done{false};

    do {
        std::cout << "\nWhat do you want to do with the list?" << std::endl
                    << "P - Print numbers" << std::endl
                    << "A - Add a number" << std::endl
                    << "M - Display mean of the numbers" << std::endl
                    << "S - Display the smallest number" << std::endl
                    << "L - Display the largest number" << std::endl
                    << "\nQ - Quit" << std::endl;   
        std::cin >> selection;

        switch(selection){
            case 'p':
            case 'P': 
                std::cout << "\nPrinting numbers...\n" << std::endl
                    << "[ ";
                for(auto i: items)
                    std::cout << i << " ";
                std::cout << "]" << std::endl;
                break;
            case 'a':
            case 'A':
                do{
                    std::cout << "How many items in the list do you want to enter?: ";
                    std::cin >> number_of_integers;
                    if(number_of_integers <= 0)
                        std::cout << "\nPlease enter positive integer!" << std::endl;
                    else 
                        done = true;
                } while(!done);
                for(int i{1}; i <= number_of_integers; ++i){
                    std::cout << "Please enter item no " << i << ": ";
                    std::cin >> temp;
                    items.push_back(temp);
                }
                number_of_integers = 0;
                temp = 0;
                done = false;
                break;
            case 'm':
            case 'M':
                if(items.size() > 0){
                    for(auto i: items)
                        mean += i;
                    mean /= items.size();
                    std::cout << "The mean of all items in list is: "
                                << mean << std::endl;
                    mean = 0.0;                    
                } else
                    std::cout << "\nNo items in list!" << std::endl;
                break;
            case 's':
            case 'S':
                if(items.size() > 0){            
                    temp = items.at(0);
                    for(auto i: items)
                        if(temp > i)
                            temp = i;
                    std::cout << "\nThe smallest item in the list is: "
                                // << "your PP xD"
                                << temp << std::endl;
                    temp = 0;
                } else
                    std::cout << "\nNo items in list!" << std::endl;                
                break;
            case 'l':
            case 'L':
                if(items.size() > 0){            
                    temp = items.at(0);
                    for(auto i: items)
                        if(temp < i)
                            temp = i;            
                    std::cout << "\nThe largest item in the list is: "
                                // << "my PP (-_-)"
                                << temp << std::endl;
                    temp = 0;
                } else
                    std::cout << "\nNo items in list!" << std::endl;                
                break;
            case 'q':
            case 'Q':
                std::cout << "\nFINALLY! I'M FREE! BYE LADS!\n" << std::endl;
                break;
            default: std::cout << "\nUnknown selection, please try again\n" << std::endl;
        }
    } while (selection != 'q' && selection != 'Q');

    std::cout << "\nBRAVO 6 going dark!\n" << std::endl;
    return 0;

} 