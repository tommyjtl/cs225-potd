#include "Bar.h"

namespace potd
{
    Bar::Bar(const Bar &other)
    {
        _copy(other);
    }

    const Bar &Bar::operator=(const Bar &other)
    {
        if (this != &other)
        {
            _clear();
            _copy(other);
        }
        return *this;
    }

    Bar::~Bar()
    {
        _clear();
    }

    void Bar::_copy(const Bar &other)
    {
        f_ = new Foo(*other.f_); // other.f_;
    }

    void Bar::_clear()
    {
        delete f_;
    }
};