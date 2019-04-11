#include <iostream>
#include <iomanip>
#include "cast.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        Cast cast(argv[1]);
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "char: ";
        try
        {
            int tmp = static_cast<int>(cast);
            if (tmp >= 32 && tmp <= 126)
                std::cout << "'" << static_cast<char>(cast) << "'" << std::endl;
            else
                std::cout << "Non displayable" << std::endl;
        }
        catch (Cast:: СastException &D)
        {
            std::cout << D.what() << std::endl;
        }
        std::cout << "int: ";
        try
        {
            int tmp2 = static_cast<int>(cast);
            std::cout << tmp2 << std::endl;
        }
        catch (Cast:: СastException &D)
        {
            std::cout << D.what() << std::endl;
        }
        std::cout << "float: ";
        try
        {
            float tmp3 = static_cast<float>(cast);
            std::cout << tmp3 << "f" << std::endl;
        }
        catch (Cast:: СastException &D)
        {
            std::cout << D.what() << std::endl;
        }
        std::cout << "double: ";
        try
        {
            double tmp4 = static_cast<double>(cast);
            std::cout << tmp4 << std::endl;
        }
        catch (Cast:: СastException &D)
        {
            std::cout << D.what() << std::endl;
        }
    }
    else
        std::cout << "Invalid argument number(\n";
    return 0;
}