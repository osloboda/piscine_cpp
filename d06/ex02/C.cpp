#include "C.hpp"

C::C()
{
    return ;
}
C::~C()
{
    return;
}

C::C(C &D)
{
    *this = D;
    return ;
}

C& C::operator = (C const &D)
{
    (void)D;
    return *this;
}