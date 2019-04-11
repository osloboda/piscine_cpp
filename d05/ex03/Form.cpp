#include <iostream>
#include "Form.hpp"

Form::Form(std::string const name, int sgrade, int grade) : grade(grade), name(name), is_signed(false), sgrade(sgrade)

{
    if (sgrade < 1 || grade < 1)
        throw Form::GradeTooHighException();
    else if (sgrade > 150 || grade > 150)
        throw Form::GradeTooLowException();
    else
        return;
}

Form::Form(Form const &D) : grade(D.grade), name(D.name), is_signed(D.is_signed), sgrade(D.sgrade)
{
    *this = D;
    return ;
}

Form::Form(): grade(1), sgrade(1)
{
    return;
}

Form::~Form()
{
    return;
}

Form::GradeTooHighException::GradeTooHighException()
{
    return;
}

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const &D)
{
    *this = D;
    return;
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
    return;
}

Form::GradeTooHighException &Form::GradeTooHighException::operator = (GradeTooHighException const &D)
{
    (void)D;
    return (*this);
}

Form::GradeTooLowException::GradeTooLowException()
{
    return;
}

Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const &D)
{
    *this = D;
    return;
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
    return;
}

Form::GradeTooLowException &Form::GradeTooLowException:: operator = (GradeTooLowException const &D)
{
    (void)D;
    return (*this);
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Error: grade is small for sign");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Error: grade is big for sign");
}

const std::string& Form::getName() const
{
    return name;
}

int Form::getGrade() const
{
    return grade;
}

int Form::getSGrade() const
{
    return sgrade;
}

bool Form::getSigned() const
{
    return is_signed;
}

void Form::signForm(void)
{
    this->is_signed = true;
    return;
}

void Form::beSigned(Bureaucrat &D)
{
    if (this->is_signed)
        std::cout << "<" << D.getName() << "> cannot sign <" << this->name
                  << "> because form is already signed" << std::endl;
    else if (D.getGrade() > this->sgrade)
    {
        std::cout << "<" << D.getName() << "> cannot sign <" << this->name << "> because ";
        throw Form::GradeTooLowException();
    }
    else
    {
        std::cout << "<" << D.getName() << "> signs <" << this-> name << ">" << std::endl;
        signForm();
    }

}

std::ostream& operator << (std::ostream &os, Form const &D)
{
    os << "name: " << D.getName() << std::endl << "signing grade: " << D.getSGrade() << std::endl << "execution grade: " << D.getGrade() << std::endl;
    if (D.getSigned())
        os << "Form is signed." << std::endl;
    else
        os << "Form not signed yet." << std::endl;
    return (os);
}

Form& Form::operator = (Form const &D)
{
    this->is_signed = D.is_signed;
    return *this;
}
