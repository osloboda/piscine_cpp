#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"


int main(void)
{
    {
        Bureaucrat test("wyjntu", 1);
        ShrubberyCreationForm test3("test");
        test3.execute(test);
        test3.beSigned(test);
        test.executeForm(test3);
        Bureaucrat test2("mtyku,y", 149);
        try {
            test2.executeForm(test3);
            test3.execute(test);
        }
        catch (Form::GradeTooHighException &e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        Bureaucrat test("wyjntu", 1);
        PresidentialPardonForm test3("test");
        test3.execute(test);
        test3.beSigned(test);
        test.executeForm(test3);
        Bureaucrat test2("mtyku,y", 149);
        try {
            test2.executeForm(test3);
            test3.execute(test);
        }
        catch (Form::GradeTooHighException &e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        Bureaucrat test("wyjntu", 1);
        RobotomyRequestForm test3("test");
        test3.execute(test);
        test3.beSigned(test);
        test.executeForm(test3);
        Bureaucrat test2("mtyku,y", 149);
        try {
            test2.executeForm(test3);
            test3.execute(test);
            test3.execute(test);
            test3.execute(test);
        }
        catch (Form::GradeTooHighException &e) {
            std::cout << e.what() << std::endl;
        }
    }
}