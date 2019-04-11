#include "Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(Intern &D)
{
    *this = D;
    return ;
}

Intern::~Intern()
{
    return ;
}

Intern& Intern::operator = (Intern const &D)
{
    (void)D;
    return *this;
}

Form* Intern::makeForm(std::string form, std::string target)
{
    if (form == "shrubbery creation")
    {
        std::cout << "Intern creates " << form << std::endl;
        return new ShrubberyCreationForm(target);
    }
    else if (form == "robotomy request")
    {
        std::cout << "Intern creates " << form << std::endl;
        return new RobotomyRequestForm(target);
    }
    else if (form == "presidential pardon")
    {
        std::cout << "Intern creates " << form << std::endl;
        return new PresidentialPardonForm(target);
    }
    else
        std::cout << "Unknown form type" << form << std::endl;
    return (NULL);
}