#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form(target, 72, 45)
{
    return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &D) : Form(D.getName(), 72, 45)
{
    *this = D;
    return;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    return;
}

RobotomyRequestForm &RobotomyRequestForm::operator = (RobotomyRequestForm const &D)
{
    (void)D;
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &D) const
{
    static int i = 0;
    if (this->getSigned() && (D.getGrade() <= this->getGrade()))
    {
        std::cout << "Vrooooooom OOOps shpshsssssss" << std::endl;
        if (!(i % 2))
            std::cout << D.getName() << " has been robotomized successfully" << std::endl;
        else
            std::cout << D.getName() << " has failed to be robotomized" << std::endl;
        i++;
    }
    else if (!this->getSigned())
        std::cout << "A Bureaucrat must signed this form." << std::endl;
    else
        throw Form::GradeTooLowException();
}

std::ostream& operator << (std::ostream &os, RobotomyRequestForm const &D)
{
    os << "name: " << D.getName() << std::endl << "signing grade: " << D.getSGrade() << std::endl << "execution grade: " << D.getGrade() << std::endl;
    if (D.getSigned())
        os << "Form is signed." << std::endl;
    else
        os << "Form not signed yet." << std::endl;
    return (os);
}
