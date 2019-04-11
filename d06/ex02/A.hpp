#ifndef A_HPP
# define A_HPP

#include "base.hpp"

class A : public Base
{
    public:
        A();
        A(A &);
        virtual ~A();
        A &operator = (A const &);
};

#endif