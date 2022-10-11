// Your code here! :)
#include "q6.h"
#include "student.h"

namespace potd
{
    void graduate(Student &student)
    {
        student.set_grade(student.get_grade() + 1);
    }
}