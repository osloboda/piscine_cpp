#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

#include <iostream>
#include <string>
#include "Form.hpp"

class	RobotomyRequestForm : public Form
{
public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(RobotomyRequestForm &);
    virtual ~RobotomyRequestForm();
    RobotomyRequestForm &operator=(RobotomyRequestForm const &);
    void execute(Bureaucrat const &) const;
};

std::ostream	&operator<<(std::ostream &os, RobotomyRequestForm const &);

#endif