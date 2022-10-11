// Your code here! :)
#pragma once

#include <string>

using std::string;

namespace potd
{
    class Student
    {
    public:
        Student()
        {
            name_ = "";
            grade_ = 0;
        };
        Student(string name, unsigned grade)
        {
            name_ = name;
            grade_ = grade;
        };
        string get_name();
        void set_name(string name);

        unsigned get_grade();
        void set_grade(unsigned grade);

    private:
        string name_;
        unsigned grade_;
    };
}