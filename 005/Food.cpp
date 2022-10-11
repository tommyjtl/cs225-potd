// Your code here
#include "Food.h"

Food::Food()
{
    name_ = "";
    quantity_ = 0;
}

Food::Food(string name, unsigned quantity)
{
    name_ = name;
    quantity_ = quantity;
}

string Food::get_name() { return name_; }

void Food::set_name(string name)
{
    name_ = name;
}

int Food::get_quantity() { return quantity_; }

void Food::set_quantity(unsigned quantity)
{
    quantity_ = quantity;
}