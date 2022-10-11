// Your code here! :)
#include <iostream>

#include "student.h"
#include "q6.h"

using namespace potd;

int main()
{
    potd::Student student;
    student.set_name("Sally");
    student.set_grade(5);

    std::cout << student.get_name() << " is in grade " << student.get_grade() << std::endl;

    potd::graduate(student);

    std::cout << student.get_name() << " is in grade " << student.get_grade() << std::endl;

    return 0;
}