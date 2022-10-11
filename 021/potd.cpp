#include "potd.h"
#include <algorithm>
#include <cmath>

/** Returns the sum of elements between start to end.
    The value at start is included, while the value at end is not.
    */
double sum(vector<double>::iterator start, vector<double>::iterator end)
{
    double output = 0.0;
    for (auto it = start; it != end; ++it)
        output = output + *it;
    return output;
}

/** Returns an iterator that points to the element with the largest value between start and end. */
vector<double>::iterator max_iter(vector<double>::iterator start, vector<double>::iterator end)
{
    vector<double>::iterator max = start;
    for (auto it = start; it != end; ++it)
    {
        if (*it >= *max)
        {
            max = it;
        }
    }
    return max;
}

/** Sort, in descending order, part of an array between start to end.
    Hint: use max_iter.
*/
void sort_vector(vector<double>::iterator start, vector<double>::iterator end)
{
    // vector<double>::iterator max_iter = std::max_element(start, end);
    std::sort(start, end, std::greater<double>());
}