#ifndef CAST_HPP
# define CAST_HPP

#include <string>

class Cast
{
    public:
    Cast();
    Cast(Cast const&);
    Cast(std::string);
    Cast &operator = (Cast const &);
    ~Cast();
    class СastException : public std::exception
    {
        public:
        СastException();
        СastException(СastException const &);
        virtual ~СastException() throw();
        СastException &operator = (СastException const &);
        virtual const char* what() const throw();
    };
    operator int() const;
    operator float() const;
    operator double() const;
    operator char() const;
private:
    std::string str;
};

#endif