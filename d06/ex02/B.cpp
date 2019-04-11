#include "B.hpp"

B::B()
{
    return ;
}
B::~B()
{
    return;
}

B::B(B &D)
{
    *this = D;
    return ;
}

B& B::operator = (B const &D)
{
    (void)D;
    return *this;
}