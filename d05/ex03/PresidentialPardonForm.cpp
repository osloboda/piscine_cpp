#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form(target, 25, 5)
{
    return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &D) : Form(D.getName(), 25, 5)
{
    *this = D;
    return;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    return;
}

PresidentialPardonForm &PresidentialPardonForm::operator = (PresidentialPardonForm const &D)
{
    (void)D;
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &D) const
{
    if ((this->getSigned()) && (D.getGrade() <= this->getGrade()))
        std::cout << D.getName() << " has been pardoned by Zafod Beeblebrox" << std::endl;
    else if (!this->getSigned())
        std::cout << "A Bureaucrat must signed this form." << std::endl;
    else
        throw Form::GradeTooLowException();
}

std::ostream& operator << (std::ostream &os, PresidentialPardonForm const &D)
{
    os << "name: " << D.getName() << std::endl << "signing grade: " << D.getSGrade() << std::endl << "execution grade: " << D.getGrade() << std::endl;
    if (D.getSigned())
        os << "Form is signed." << std::endl;
    else
        os << "Form not signed yet." << std::endl;
    return (os);
}
