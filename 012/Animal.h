// Animal.h
#pragma once

#include <string>
#include <iostream>

using std::string;

class Animal
{
public:
    Animal()
    {
        type_ = "cat";
        food_ = "fish";
    };

    Animal(string type, string food)
    {
        type_ = type;
        food_ = food;
    }

    string getType();
    void setType(string type);

    string getFood();
    void setFood(string food);

    virtual string print();

protected:
    string food_;

private:
    string type_;
};