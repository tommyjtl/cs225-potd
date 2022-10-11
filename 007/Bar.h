#pragma once

#include "Foo.h"
#include <iostream>
#include <string>

using potd::Foo;
using std::string;

namespace potd
{
    class Bar
    {
    public:
        Bar(string name)
        {
            f_ = new Foo(name);
        };
        Bar(const Bar &other);
        const Bar &operator=(const Bar &other);
        ~Bar();

        string get_name() { return f_->get_name(); };

    private:
        Foo *f_;

        void _copy(const Bar &other);
        void _clear();
    };
};