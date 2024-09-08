#include <iostream>
#ifndef _MYCLASS_
#define _MYCLASS_

class myClass{

    private:
    const int*  x;

    public:
    myClass(int x);
    myClass(const myClass &source);
    myClass(myClass &&source) noexcept;
    ~myClass();
    myClass &operator=(const myClass &source);
    myClass &operator+(myClass const &source);
    myClass &operator++();
    myClass &operator-(myClass const &source);
    myClass &operator--();
    void disp_x() const;
    void addition(int add);
};
#endif