// Your code here
#pragma once

#include <iostream>
#include <string>
using std::string;

class Food
{
public:
    Food();
    Food(string name, unsigned quantity);
    string get_name();
    void set_name(string name);
    int get_quantity();
    void set_quantity(unsigned quantity);

private:
    string name_;
    unsigned quantity_;
};