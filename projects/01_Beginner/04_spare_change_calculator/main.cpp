#include "main.h"

using namespace std;
 
int main()
{
    const int dollar_value{100}, quarter_value{25}, dime_value{10}, nickel_value{5};

    cout << "this is change calculator or something. Pease enter the amount of cents:" << endl;

    int cents{0};
    cin >> cents;

    int dollars, quarters, dimes, nickles{0};

    dollars = cents / dollar_value;
    cents %= dollar_value;
    quarters = cents / quarter_value;
    cents %= quarter_value;
    dimes = cents / dime_value;
    cents %= dime_value;
    nickles = cents /nickel_value;
    cents %= nickel_value;

    cout << "that would be:" << endl;
    cout << dollars << " dollars" << endl;
    cout << quarters << " quarters" << endl;
    cout << dimes << " dimes" << endl;
    cout << nickles << " nickles" << endl;
    cout << cents << " pennies" << endl;
    
    return 0;
}