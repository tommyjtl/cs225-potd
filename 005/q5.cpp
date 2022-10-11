// your code here
#include "q5.h"

void increase_quantity(Food *food)
{
    unsigned prev = food->get_quantity();
    food->set_quantity(prev + 1);
}