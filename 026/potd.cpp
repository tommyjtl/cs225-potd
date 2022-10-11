// Your code here
#include "potd.h"

#include <vector>

const std::vector<string> fortunes{"As you wish!",
                                   "Nec spe nec metu!",
                                   "Do not attempt when you are uncertain",
                                   "Quick fox jumps over the lazy dog.",
                                   "Amor fati!"};

string getFortune(const string &s)
{
    // The fortune must be the same when the same string is given (it must be deterministic).

    // There must be at least 5 different fortunes and every string must map to one fortune.
    // The fortunes must not be the empty string.

    return fortunes.at(s.size() % fortunes.size());
}