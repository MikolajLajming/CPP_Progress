#include "main.h"

using namespace std;

int main() 
{

    string input{};
    getline(cin, input);

    string temp_string{};
    vector<string> tree{};

    for(size_t i{input.size()}; i > 0; --i){
        temp_string.clear();
        for(size_t j{1}; j < input.size(); ++j){
            if(i <= j){
                temp_string += input.at(j-i);
            } else
                temp_string += ' ';
        }
        for(size_t k {input.size()}; k > 0; --k){
            if(k >= i)
                temp_string += input.at(k-i);
        }
        cout << temp_string << endl;
    }

    return 0;

} 