
#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &D) : name(D.getName())
{
    *this = D;
    return ;
}

Bureaucrat::Bureaucrat()
{
    return;
}

Bureaucrat::~Bureaucrat()
{
    return;
}

void Bureaucrat::incrementGrade()
{
    if (this->getGrade() - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->getGrade() + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->grade++;
}

const std::string& Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

std::ostream & operator<<(std::ostream &os, Bureaucrat const &D)
{
    return os << D.getName() << ", bureaucrat grade " << D.getGrade() << std::endl;;
}

Bureaucrat& Bureaucrat::operator = (Bureaucrat const &D)
{
    this->grade = D.getGrade();
    return *this;
}
