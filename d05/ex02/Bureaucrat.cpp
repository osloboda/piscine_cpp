#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : grade(grade), name(name)
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

void Bureaucrat::executeForm(Form const &D)
{
    if (this->grade < D.getGrade())
    {
        std::cout << "Bureaucrat " << this->name << " executes " << D.getName() << std::endl;
        D.execute(*this);
    }
    else
        std::cout << "Bureaucrat " << this->name << " grade is low" << std::endl;
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
{
    return;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const &D)
{
    *this = D;
    return;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
    return;
}

Bureaucrat::GradeTooHighException &Bureaucrat::GradeTooHighException::operator = (GradeTooHighException const &D)
{
    (void)D;
    return (*this);
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{
    return;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const &D)
{
    *this = D;
    return;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
    return;
}

Bureaucrat::GradeTooLowException &Bureaucrat::GradeTooLowException:: operator = (GradeTooLowException const &D)
{
    (void)D;
    return (*this);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Error: grade < 1");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Error: grade > 150");
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

std::ostream & operator << (std::ostream &os, Bureaucrat const &D)
{
    return os << D.getName() << ", bureaucrat grade " << D.getGrade() << std::endl;;
}

Bureaucrat& Bureaucrat::operator = (Bureaucrat const &D)
{
    this->grade = D.getGrade();
    return *this;
}
