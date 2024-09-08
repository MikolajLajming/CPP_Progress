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

myClass &myClass::operator=(const myClass &source)
    {
        if(this == &source)
            return *this;
        else{
            delete x;
            x = new int(*source.x);
            return *this;
        }
    }

myClass &myClass::operator+(myClass const &source)
    {
        int* add(new int(0));
        *add = *x;
        delete x;
        x = new int(*add + *source.x);
        delete add;
        return *this;
    }

myClass &myClass::operator++()
    {
        int* incr(new int(0));
        *incr = *x;
        delete x;
        x = new int(++*incr);
        delete incr;
        return *this;
    }

myClass &myClass::operator-(myClass const &source)
    {
        int* subtr(new int(0));
        *subtr = *x;
        delete x;
        x = new int(*subtr - *source.x);
        delete subtr;
        return *this;
    }

myClass &myClass::operator--()
    {
        int* decr(new int(0));
        *decr = *x;
        delete x;
        x = new int(--*decr);
        delete decr;
        return *this;
    }

void myClass::disp_x() const
    {
        std::cout << *x << std::endl;
    };