#include <iostream>
#include "Thing.h"

int main()
{
    potd::Thing *t1 = new potd::Thing(5);
    potd::Thing *t2 = new potd::Thing(5);

    t1->set_property("name", "Kermit");
    t1->set_property("color", "Green");
    t1->set_property("name", "Tommy");

    std::cout << t1->get_property("name") << " is " << t1->get_property("color") << std::endl;

    *t2 = *t1;
    t1->set_property("name", "Grover");
    t1->set_property("color", "Blue");

    std::cout << t2->get_property("name") << " is " << t2->get_property("color") << std::endl;
    std::cout << t1->get_property("name") << " is " << t1->get_property("color") << std::endl;

    // std::cout << __LINE__ << std::endl;
    delete t1;
    // std::cout << __LINE__ << std::endl;
    delete t2;
    // std::cout << __LINE__ << std::endl;
}
