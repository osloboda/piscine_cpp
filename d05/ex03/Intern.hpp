#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Form.hpp"

class Form;

class	Intern
{
	public:
		Intern();
		Intern(Intern &);
		virtual ~Intern();
		Intern &operator=(Intern const &);
		Form *makeForm(std::string form, std::string target);

};

#endif