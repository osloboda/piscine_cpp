#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    Bureaucrat bureaucrat("bureaucrat", 5);
    Form		form("Declaration of Independence", 50, 50);
    std::cout << form << std::endl;
    form.beSigned(bureaucrat);
    std::cout << form << std::endl;
    form.beSigned(bureaucrat);
    try
    {
        Bureaucrat bureaucrat("bureaucrat", 51);
        Form form("Declaration of Independence", 50, 50);
        form.beSigned(bureaucrat);
        std::cout << form << std::endl;
    }
    catch(std::exception &D)
    {
        std::cout << D.what() << std::endl;
    }
}