// Animal.cpp
#include "Animal.h"

string Animal::getType() { return type_; }

void Animal::setType(string type)
{
    type_ = type;
}

string Animal::getFood() { return food_; }

void Animal::setFood(string food)
{
    food_ = food;
}

string Animal::print()
{
    return "I am a " + type_;
}