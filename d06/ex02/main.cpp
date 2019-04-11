#include <iostream>
#include "base.hpp"
#include "B.hpp"
#include "C.hpp"
#include "A.hpp"

Base			*generate(void)
{
    switch (rand() % 3)
    {
        case 0:
            return (new A());
        case 1:
            return (new B());
        default:
            return (new C());
    }
}

void			identify_from_pointer(Base *D)
{
    if (dynamic_cast<A*>(D))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(D))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(D))
        std::cout << "C\n";
}

void			identify_from_reference(Base &D)
{
    if (dynamic_cast<A*>(&D))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(&D))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(&D))
        std::cout << "C\n";
}

int	main()
{
    srand(time(0));
    Base *base = generate();
    identify_from_pointer(base);
    identify_from_reference(*base);
    delete base;
    return (0);
}