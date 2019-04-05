#include <iostream>
#include "RadScorpion.hpp"
#include "RadScorpion.hpp"

RadScorpion::RadScorpion(void): Enemy(80, "RadScorpion")
{
    std::cout << "* click click click *"<< std::endl;
}

RadScorpion::RadScorpion(RadScorpion const &D): Enemy(D)
{
    std::cout << "* click click click *"<< std::endl;
}

RadScorpion::~RadScorpion()
{
    std::cout << "* SPROTCH *"<< std::endl;
}