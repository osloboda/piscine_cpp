#include "A.hpp"

A::A()
{
    return ;
}
A::~A()
{
    return;
}

A::A(A &D)
{
    *this = D;
    return ;
}

A& A::operator = (A const &D)
{
    (void)D;
    return *this;
}