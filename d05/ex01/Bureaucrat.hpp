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
    void incrementGrade();
    void decrementGrade();
    class GradeTooHighException : public std::exception
    {
        public:
            GradeTooHighException();
            GradeTooHighException(GradeTooHighException const &);
            virtual ~GradeTooHighException() throw();
            virtual const char* what() const throw();
            GradeTooHighException &operator = (GradeTooHighException const &);
    };
    class GradeTooLowException : public std::exception
    {
        public:
            GradeTooLowException();
            GradeTooLowException(GradeTooLowException const &);
            virtual ~GradeTooLowException() throw();
            virtual const char* what() const throw();
            GradeTooLowException &operator = (GradeTooLowException const &);
    };
};

std::ostream & operator<<(std::ostream &os, Bureaucrat const &);

#endif
