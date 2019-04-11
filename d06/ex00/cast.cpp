#include "cast.hpp"

Cast::Cast()
{

}

Cast::Cast(Cast const &D)
{
    *this = D;
    return;
}

Cast::~Cast()
{
    return;
}

Cast::Cast(std::string str) :str(str)
{
    return ;
}

Cast& Cast::operator = (Cast const &D)
{
    this->str = D.str;
    return *this;
}

Cast::operator char() const
{
    int tmp = 0;
    try
    {
        tmp = std::stoi(this->str);
    }
    catch (const std::exception &D)
    {
        throw (СastException());
    }
    return (static_cast<char>(tmp));

}

Cast::operator int() const
{
    int tmp = 0;
    try
    {
        tmp = std::stoi(this->str);
    }
    catch (const std::exception &D)
    {
        throw (СastException());
    }
    return (tmp);

}

Cast::operator float() const
{
    float tmp = 0.0;
    try
    {
        tmp = std::stof(this->str);
    }
    catch (const std::exception &D)
    {
        throw (СastException());
    }
    return (tmp);

}

Cast::operator double() const
{
    float tmp = 0.0;
    try
    {
        tmp = std::stof(this->str);
    }
    catch (const std::exception &D)
    {
        throw (СastException());
    }
    return (tmp);

}

Cast::СastException::СastException(void)
{
    return;
}

Cast::СastException::СastException(СastException const &D)
{
    *this = D;
    return;
}

Cast::СastException::~СastException(void) throw()
{
    return;
}

Cast::СastException &Cast::СastException::operator = (СastException const &D)
{
    (void)D;
    return (*this);
}

const char* Cast::СastException::what() const throw()
{
    return ("impossible");
}
