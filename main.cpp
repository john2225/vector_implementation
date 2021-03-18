#include <iostream>
#include "Vector.h"


int main()
{
    Vector<int> a;
    a.push_back(12);
    a.push_back(24);
    a.push_back(67);
    
    try
    {
        std::cout << a.at(2) << std::endl;
    }
    catch(std::out_of_range e)
    {
        std::cout << e.what() << std::endl;
    }
    
    Vector<int> b;
    b = a;
    b[0] = a[2];
    std::cout << b.at(0) << std::endl;
    return 0;
}
