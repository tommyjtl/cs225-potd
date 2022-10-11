/*
For Base, have foo() return "Sam I Am"
For Derived, have foo() return "I will not eat them."
For Base, have bar() return "Green Eggs"
For Derived, have bar() return "And Ham"
Note that one of these strings includes a period, but the others do not.
Method foo() should be a regular method.
Method bar() should be virtual.
Create a virtual destructor for both classes. It won't do anything except keep the compiler from complaining.
Do not create any namespaces for this problem.
*/

#include "Derived.h"

std::string Derived::foo()
{
    return "I will not eat them.";
}

std::string Derived::bar()
{
    return "And Ham";
}

Derived::~Derived()
{
    // does nothing;
}