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
    void disp_x() const;
};
#endif