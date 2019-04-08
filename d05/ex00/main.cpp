
#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat loser("good", 6);
    loser.incrementGrade();
    loser.incrementGrade();
    loser.incrementGrade();
    loser.incrementGrade();
    loser.incrementGrade();
    try
    {
        loser.incrementGrade();
    }
    catch(std::exception &D)
    {
        std::cout << D.what() << std::endl;
    }
    try
    {
        Bureaucrat man("man", 151);
    }
    catch(std::exception &D)
    {
        std::cout << D.what() << std::endl;
    }
    try
    {
        Bureaucrat man("man", 0);
    }
    catch(std::exception &D)
    {
        std::cout << D.what() << std::endl;
    }
    try
    {
        Bureaucrat man("man", 150);
        man.decrementGrade();
    }
    catch(std::exception &D)
    {
        std::cout << D.what() << std::endl;
    }
}