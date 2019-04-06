#include <algorithm>
#include "Squad.hpp"

Squad::Squad(void): count(0), units(nullptr)
{
    return ;
}

Squad::~Squad(void)
{
    for (int i = 0; i < count; i++)
    {
        delete this->units[i];
    }
    delete []units;
}

int Squad::getCount() const
{
    return this->count;
}

Squad::Squad(Squad const &D)
{
    *this = D;
}

ISpaceMarine* Squad::getUnit(int u) const
{
    return this->units[u];
}

int				Squad::push(ISpaceMarine *unit)
{
    ISpaceMarine **units;

    units = new ISpaceMarine*[count + 1];
    if (!count)
    {
        *units = unit;
        units[1] = nullptr;
        this->units = units;
        return ++count;
    }
    else
    {
        for (int i = 0; i < count; i++)
            units[i] = this->units[i]->clone();
        units[count] = unit;
    }
    this->count++;
    if (this->units)
        delete []this->units;
    this->units = units;
    return count;
}

Squad			&Squad::operator = (Squad const &D)
{
    if (this != &D)
    {
        for (int i = 0; i < count; i++)
            delete units[i];
        count = D.getCount();
        units = new ISpaceMarine*[count];
        for (int i = 0; i < count; i++)
            units[i] = D.getUnit(i);
    }
    return (*this);
}
