// Pet.h
#pragma once

#include "Animal.h"
#include <string>

class Pet : public Animal
{
public:
    // Write a default constructor for Pet that initializes
    // type_ to cat, food_ to "fish", name_ to "Fluffy", and owner_name_ to "Cinda"
    // and a constructor that takes in the
    // type of animal, type of food, name, and owner name as parameters.
    Pet() : Animal("cat", "fish")
    {
        name_ = "Fluffy";
        owner_name_ = "Cinda";
    };

    Pet(std::string type, std::string food, std::string name, std::string owner_name) : Animal(type, food)
    {
        // type_ = type;
        // food_ = food;
        name_ = name;
        owner_name_ = owner_name;
    };

    // Write functions that get and set the type of
    // food_, name_, and owner_name_ of the Pet class.
    // Follow the naming scheme of the other getters and setters.
    void setFood(std::string nu_food);
    void setName(std::string nu_name);
    void setOwnerName(std::string nu_owner_name);

    std::string getFood();
    std::string getName();
    std::string getOwnerName();

    // Write a function print that returns the string
    // "My name is NAME" where NAME is the value of the name_ variable.
    std::string print();

private:
    std::string name_;
    std::string owner_name_;
};