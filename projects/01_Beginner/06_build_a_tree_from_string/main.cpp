#include "main.h"

using namespace std;

int main() 
{
    string input{};
    getline(cin, input);
    for(size_t i{input.size()}; i > 0; --i){      
        for(size_t j{1}; j < input.size(); ++j){
            if(j < i)
                cout << ' ';
            else
                cout << input.at(j-i);
        }
        for(size_t k{input.size()}; k > 0; --k){
            if(k >= i)
                cout << input.at(k-i);
        }
        cout << endl;       
    }
    return 0;
} 