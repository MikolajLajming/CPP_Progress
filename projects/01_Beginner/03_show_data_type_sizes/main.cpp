#include "main.h"

using namespace std;

int main(){

    cout << "sizeof data type on this machine using this compiler" << endl;
    cout <<  "======================================================" << endl;
    cout << "char: " << sizeof(char) << " byte." << endl;
    cout << "bool: " << sizeof(bool) << " byte." << endl;
    cout << "short: " << sizeof(short) << " bytes." << endl;
    cout << "int: " << sizeof(int) << " bytes." << endl;
    cout << "long: " << sizeof(long) << " bytes." << endl;
    cout << "long long: " << sizeof(long long) << " bytes." << endl;
    cout << "unsigned short: " << sizeof(unsigned short) << " bytes." << endl;
    cout << "unsigned int: " << sizeof(unsigned int) << " bytes." << endl;
    cout << "unsigned long: " << sizeof(unsigned long) << " bytes." << endl;
    cout << "unsigned long long: " << sizeof(unsigned long long) << " bytes." << endl;
    cout <<  "======================================================" << endl;
    cout << "float: " << sizeof(float) << " bytes." << endl;
    cout << "double: " << sizeof(double) << " bytes." << endl;
    cout << "long double: " << sizeof(long double) << " bytes." << endl;
    cout <<  "======================================================" << endl;

    return 0;
}