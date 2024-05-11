#include "main.h"

using namespace std;

int main() 
{ 
    cout << "Hello, simple something here. We're gonna ask you to enter some integers and we'll put them into a list you can iteract with." << endl;
    int number_of_integers{0};

    cout << "How many items in the list do you want to enter?: ";
    cin >> number_of_integers;

    vector<int> items{};
    int temp{0};

    if(number_of_integers > 0){
        for(int i{1}; i <= number_of_integers; ++i){
            cout << "Please enter item no " << i << ": ";
            cin >> temp;
            items.push_back(temp);
        }
        temp = 0;
        number_of_integers = 0;
        cout << "\nThe list looks like this now:\n" << endl
                    << "[ ";
        for(auto i: items)
            cout << i << " ";
        cout << "]" << endl;        
    }
    
    char selection{0};
    double mean{0.0};
    bool done{false};

    do {
        cout << "\nWhat do you want to do with the list?" << endl
                    << "P - Print numbers" << endl
                    << "A - Add a number" << endl
                    << "M - Display mean of the numbers" << endl
                    << "S - Display the smallest number" << endl
                    << "L - Display the largest number" << endl
                    << "\nQ - Quit" << endl;   
        cin >> selection;

        switch(selection){
            case 'p':
            case 'P': 
                cout << "\nPrinting numbers...\n" << endl
                    << "[ ";
                for(auto i: items)
                    cout << i << " ";
                cout << "]" << endl;
                break;
            case 'a':
            case 'A':
                do{
                    cout << "How many items in the list do you want to enter?: ";
                    cin >> number_of_integers;
                    if(number_of_integers <= 0)
                        cout << "\nPlease enter positive integer!" << endl;
                    else 
                        done = true;
                } while(!done);
                for(int i{1}; i <= number_of_integers; ++i){
                    cout << "Please enter item no " << i << ": ";
                    cin >> temp;
                    items.push_back(temp);
                }
                cout << "\nThe list looks like this now:\n" << endl
                            << "[ ";
                for(auto i: items)
                    cout << i << " ";
                cout << "]" << endl;                
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
                    cout << "\nThe mean of all items in list is: "
                                << mean << endl;
                    mean = 0.0;                    
                } else
                    cout << "\nNo items in list!" << endl;
                break;
            case 's':
            case 'S':
                if(items.size() > 0){            
                    temp = items.at(0);
                    for(auto i: items)
                        if(temp > i)
                            temp = i;
                    cout << "\nThe smallest item in the list is: "
                                // << "your PP xD"
                                << temp << endl;
                    temp = 0;
                } else
                    cout << "\nNo items in list!" << endl;                
                break;
            case 'l':
            case 'L':
                if(items.size() > 0){            
                    temp = items.at(0);
                    for(auto i: items)
                        if(temp < i)
                            temp = i;            
                    cout << "\nThe largest item in the list is: "
                                // << "my PP (-_-)"
                                << temp << endl;
                    temp = 0;
                } else
                    cout << "\nNo items in list!" << endl;                
                break;
            case 'q':
            case 'Q':
                cout << "\nFINALLY! I'M FREE! BYE LADS!\n" << endl;
                break;
            default: cout << "\nUnknown selection, please try again\n" << endl;
        }
    } while (selection != 'q' && selection != 'Q');

    cout << "\nBRAVO 6 going dark!\n" << endl;
    return 0;

} 