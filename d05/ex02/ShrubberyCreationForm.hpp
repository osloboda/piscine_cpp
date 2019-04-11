#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

#include <iostream>
#include <string>
#include "Form.hpp"

class	ShrubberyCreationForm : public Form
{
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm &);
    virtual ~ShrubberyCreationForm();
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &);
    virtual void execute(Bureaucrat const &) const;
};

std::ostream	&operator<<(std::ostream &os, ShrubberyCreationForm const &);

#endif