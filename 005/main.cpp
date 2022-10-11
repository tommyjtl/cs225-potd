// your code here

#include "Food.h"
#include "q5.h"

int main()
{
    Food *food = new Food("apple", 5);

    string plural = "";
    if (food->get_quantity() > 1)
    {
        plural = "s";
    }

    std::cout << "You have " << food->get_quantity() << " " << food->get_name() << plural << std::endl;
    increase_quantity(food);

    std::cout << "You have " << food->get_quantity() << " " << food->get_name() << plural << std::endl;
    return 0;
}