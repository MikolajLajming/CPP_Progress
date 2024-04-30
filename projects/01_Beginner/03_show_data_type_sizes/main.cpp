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
    cout << "Limits" << endl;
    cout <<  "======================================================" << endl;
    cout << "MIN value of char is: " << CHAR_MIN << "." <<endl;
    cout << "MAX value of char is: " << CHAR_MAX << "." <<endl;
    cout << "MAX value of short is: " << SHRT_MIN << "." <<endl;
    cout << "MIN value of short is: " << SHRT_MAX << "." <<endl;
    cout << "MIN value of int is: " << INT_MIN << "." <<endl;
    cout << "MAX value of int is: " << INT_MAX << "." <<endl;
    cout << "MIN value of long is: " << LONG_MIN << "." <<endl;
    cout << "MAX value of long is: " << LONG_MAX << "." <<endl;
    cout << "MIN value of long long is: " << LLONG_MIN << "." <<endl;
    cout << "MAX value of long long is: " << LLONG_MAX << "." <<endl;
    cout << "MAX value of unsigned int is: " << UINT_MAX << "." <<endl;
    cout << "MAX value of unsigned long is: " << ULONG_MAX << "." <<endl;
    cout << "MAX value of unsigned long long is: " << ULLONG_MAX << "." <<endl;
    cout <<  "======================================================" << endl;
    cout << "MIN value of float is: " << FLT_MIN << "." <<endl;
    cout << "MAX value of float is: " << FLT_MAX << "." <<endl;
    cout << "MAX value of double is: " << DBL_MIN << "." <<endl;
    cout << "MIN value of double is: " << DBL_MAX << "." <<endl;
    cout << "MIN value of long double is: " << LDBL_MIN << "." <<endl;
    cout << "MAX value of long double is: " << LDBL_MAX << "." <<endl;
    return 0;
}