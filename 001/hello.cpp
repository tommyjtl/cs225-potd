/* Your code here! */

#include <string>

std::string hello()
{
    int age_ = 26;
    std::string name_ = "Tommy";
    return "Hello world! My name is " + name_ + " and I am " + std::to_string(age_) + " years old.";
}
