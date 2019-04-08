#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>

class Bureaucrat
{
private:
    Bureaucrat();
    int grade;
    const std::string name;
public:
    Bureaucrat(std::string name, int grade);
    Bureaucrat(Bureaucrat const &);
    ~Bureaucrat();
    Bureaucrat& operator = (Bureaucrat const &);
    const std::string &getName() const;
    int getGrade() const;
    class GradeTooHighException : public std::exception {};
    class GradeTooLowException : public std::exception {};
    void incrementGrade();
    void decrementGrade();
};

std::ostream & operator<<(std::ostream &os, Bureaucrat const &);

#endif
