#ifndef B_HPP
# define B_HPP

#include "base.hpp"

class B : public Base
{
public:
    B();
    B(B &);
    virtual ~B();
    B &operator = (B const &);
};

#endif