#include "main.h"

using namespace std;
int main() {
    cout << "Welcome to area calculator!" << endl;
    cout << "Please enter width of the area in ft (and please use integers only, I'm dumb as a jellyfish): ";
    int area_width {0};
    cin >> area_width;
    cout << "\nPlease enter area length in ft (yes! you guessed it! Integers only): ";
    int area_length {0};
    cin >> area_length;
    cout << "\nThe size of this area is: " << area_width*area_length << " square ft.\nCould be a luxury apartmnent!" << endl;
    return 0;
}