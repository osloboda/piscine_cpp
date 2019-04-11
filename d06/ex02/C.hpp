#ifndef C_HPP
# define C_HPP

#include "base.hpp"

class C : public Base
{
public:
    C();
    C(C &);
    virtual ~C();
    C &operator = (C const &);
};

#endif