#include <iostream>
#include "Array.hpp"

int				main(void)
{
    Array<int> t(10);
    try
    {
       for (unsigned int i = 0; i < t.getSize(); i++)
           t[i] = i;
       for (unsigned int i = 0; i < t.getSize(); i++)
           std::cout << t[i] << " ";
        std::cout << "\n";
    }
    catch (std::exception &D)
    {
        std::cout << D.what() << std::endl;
    }
    return (0);
}
