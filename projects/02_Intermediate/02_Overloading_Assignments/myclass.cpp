#include "myclass.hpp"

myClass::myClass(int x) 
    :   x{new int {x}}
    {};

myClass::myClass(const myClass &source) 
    :   myClass(*source.x)
    {
        std::cout << "Deep copy constructor called for: " << *x << std::endl;
    };

myClass::myClass(myClass &&source) noexcept
    :   x{new int{*source.x}}
    {
        source.x = nullptr;
        std::cout << "Move constructor called for: " << *x << std::endl;
    };

myClass::~myClass()
    {
        if(x == nullptr)
            std::cout << "Destructor called for nullptr" << std::endl;
        else
            std::cout << "Destructor called for: " << *x << std::endl;
        delete x;
    };

void myClass::disp_x() const
    {
        std::cout << *x << std::endl;
    };
