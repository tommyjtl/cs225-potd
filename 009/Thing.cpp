// Your code here!
#include "Thing.h"
#include <iostream>

using std::string;

namespace potd
{
    // a constructor that takes the max size of the properties and values arrays.
    Thing::Thing(int size)
    {
        props_max_ = size;
        props_ct_ = 0;
        properties_ = new std::string[size];
        values_ = new std::string[size];
    }

    // a copy constructor.
    Thing::Thing(const Thing &other)
    {
        _copy(other);
    }

    Thing &Thing::operator=(const Thing &other)
    {
        if (this != &other)
        {
            _destroy();
            _copy(other);
        }
        return *this;
    }

    Thing::~Thing()
    {
        _destroy();
    }

    void Thing::_copy(const Thing &other)
    {
        props_ct_ = other.props_ct_;
        props_max_ = other.props_max_;

        properties_ = new std::string[props_max_];
        values_ = new std::string[props_max_];

        for (int i = 0; i < props_max_; i++)
        {
            properties_[i] = other.properties_[i];
            values_[i] = other.values_[i];
        }
    }

    void Thing::_destroy()
    {
        delete[] values_;
        delete[] properties_;
    }

    // Takes a property name and value, and inserts them into the arrays.
    // Returns the index into the array if successul,
    // and -1 if the array was full.
    // If the property name already exists, replace the value.
    int Thing::set_property(string name, string value)
    {
        for (int i = 0; i < props_max_; ++i)
        {
            if (properties_[i] == name)
            {
                properties_[i] = name;
                values_[i] = value;
                return i;
            }
        }

        if (props_ct_ == props_max_)
        {
            return -1;
        }

        properties_[props_ct_] = name;
        values_[props_ct_] = value;

        props_ct_ = props_ct_ + 1;
        return props_ct_ - 1;
    }

    // Returns the corresponding value for a given property name, or else an empty string if that property is not found.
    string Thing::get_property(string name)
    {
        for (int i = 0; i < props_max_; i++)
        {
            if (properties_[i] == name)
            {
                return values_[i];
            }
        }
        return "";
    }
}