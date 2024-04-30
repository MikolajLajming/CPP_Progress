#include "main.h"

using namespace std;
int main() {
    unsigned favourite_number {0};
    cout << "Hello World! I'd like to know - what is your favourite number? (Please use positive integers only, I'm just a dumb program)" << endl;
    cin >> favourite_number;
    cout << "OMG! " << favourite_number << " is my favourite number too! Coincidence? I THINK NOT!" << endl;
    return 0;
}