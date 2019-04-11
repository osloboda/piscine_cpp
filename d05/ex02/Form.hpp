#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        Form();
        const int grade;
        const std::string name;
        bool is_signed;
        const int sgrade;
    public:
        Form(std::string name, int sgrade, int grade);
        Form(Form const &);
        virtual ~Form();
        Form& operator = (Form const &);
        const std::string &getName() const;
        int getGrade() const;
        bool getSigned() const;
        int getSGrade() const;
        void signForm();
        virtual void execute(Bureaucrat const &D) const = 0;
        void beSigned(Bureaucrat &);
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

std::ostream & operator<<(std::ostream &os, Form const &D);

#endif