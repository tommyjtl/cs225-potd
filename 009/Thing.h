#pragma once

#include <string>

namespace potd
{
    class Thing
    {
    public:
        Thing(int);
        Thing(const Thing &);
        Thing &operator=(const Thing &);
        ~Thing();

        int set_property(std::string, std::string);
        std::string get_property(std::string);

    private:
        void _copy(const Thing &);
        void _destroy();

        std::string *properties_; // containing the names of the properties
        std::string *values_;     // containing the values of the properties
        int props_ct_;            // count how many properties we have
        int props_max_;           // return the maximum number or properties
    };
}
