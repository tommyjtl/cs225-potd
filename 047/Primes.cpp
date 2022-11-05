#include <vector>
#include "Primes.h"
#include <iostream>

std::vector<int> *genPrimes(int M)
{
    std::vector<int> *v = new std::vector<int>();
    // your code here

    std::vector<bool> sieve(M + 1, true);
    sieve[0] = false, sieve[1] = false;
    int i = 2;

    while (i * i <= M)
    {
        if (sieve[i] == true)
        {
            int j = i * i;
            while (j <= M)
            {
                sieve[j] = false;
                j = j + i;
            }
        }
        i = i + 1;
    }

    for (unsigned long i = 0; i < sieve.size(); i++)
        if (sieve[(int)i] == true)
            v->push_back(i);

    return v;
}
