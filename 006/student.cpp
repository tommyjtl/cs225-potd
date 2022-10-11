// Your code here! :)
#include "student.h"

namespace potd
{
    string Student::get_name() { return name_; }

    void Student::set_name(string name)
    {
        name_ = name;
    }

    unsigned Student::get_grade() { return grade_; }

    void Student::set_grade(unsigned grade)
    {
        grade_ = grade;
    }
}