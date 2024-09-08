#include <iostream>
#include <vector>
#include "myclass.hpp"

int main(){
    std::vector<myClass> vec;
    std::cout << vec.size() << std::endl;
    vec.push_back(myClass(3));
    vec.push_back(myClass(1));
    vec.push_back(myClass(vec.at(0)));
    vec.at(0).disp_x();
    vec.at(1).disp_x();
    vec.at(2).disp_x();

    vec.at(1) = vec.at(0);
    vec.at(1).disp_x();
    vec.at(1) = vec.at(1) + vec.at(0);
    vec.at(1).disp_x();
    vec.at(1) = vec.at(1) - vec.at(2);
    vec.at(1).disp_x();
    ++vec.at(1);
    vec.at(1).disp_x();
    --vec.at(1);
    vec.at(1).disp_x();
    vec.pop_back();
    vec.at(1).disp_x();

    return 0;
}