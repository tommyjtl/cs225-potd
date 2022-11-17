#include <string>
#include <iostream>
#include <algorithm>
// #include <vector>
#include <unordered_set>

#include "Hash.h"

unsigned long bernstein(std::string str, int M)
{
    unsigned long b_hash = 5381;
    for (int i = 0; i < (int)str.length(); ++i)
        b_hash = b_hash * 33 + str[i];
    return b_hash % M;
}

float hash_goodness(std::string str, int M)
{
    std::unordered_set<unsigned long> array;
    int permutation_count = 0;
    int collisions = 0;
    do
    {
        if (permutation_count == M)
            break;
        // Code for computing the hash and updating the array
        unsigned long hash = bernstein(str, M);

        if (array.find(hash) == array.end())
            array.insert(hash);
        else
            collisions++;

        permutation_count++;

    } while (std::next_permutation(str.begin(), str.end()));

    // Code for determining goodness
    return (float)((float)collisions) / ((float)M);
}