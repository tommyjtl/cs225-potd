// Pet.cpp
#include "Pet.h"

void Pet::setFood(std::string nu_food)
{
    food_ = nu_food;
}
void Pet::setName(std::string nu_name)
{
    name_ = nu_name;
}
void Pet::setOwnerName(std::string nu_owner_name)
{
    owner_name_ = nu_owner_name;
}

std::string Pet::getFood() { return food_; }
std::string Pet::getName() { return name_; }
std::string Pet::getOwnerName() { return owner_name_; }

std::string Pet::print()
{
    return "My name is " + name_;
}