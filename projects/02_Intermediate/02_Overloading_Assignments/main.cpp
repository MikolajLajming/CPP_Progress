#include <iostream>
#include <vector>
#include "myclass.hpp"

int main(){
    myClass noname(0);
    myClass anotherone(1);
    noname.disp_x();
    anotherone.disp_x();
    myClass copyofsomething(noname);

    std::vector<myClass> vec;
    vec.push_back(myClass(3));
    vec.push_back(myClass(4));
    vec.push_back(myClass(5));
    {
        myClass altowka(99);
    }
    std::cout << "Altowka znika :(" << std::endl;

    return 0;
}