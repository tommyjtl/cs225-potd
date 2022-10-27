#include <vector>
#include "Primes.h"
#include <stddef.h>

std::vector<int> *genPrimes(int M)
{
    std::vector<int> *v = new std::vector<int>();
    std::vector<int> *t = new std::vector<int>(M);
    int i = 0;
    int nextPrime = 2;

    for (i = 0; i < M; i++)
        (*t)[i] = 1;

    (*t)[0] = 0;
    (*t)[1] = 0;

    v->push_back(2);

    while (nextPrime < M)
    {
        for (i = nextPrime * nextPrime;
             i < M;
             i += nextPrime)
            (*t)[i] = 0;
        for (++nextPrime; nextPrime < M; nextPrime++)
            if ((*t)[nextPrime] == 1)
            {
                v->push_back(nextPrime);
                break;
            }
    }

    delete t;
    return v;
}

int numSequences(std::vector<int> *primes, int num)
{
    // your code here
    size_t pos = 0;
    int start = primes->at(pos);
    int seq_count = 0;

    while (start != primes->at(primes->size() - 1))
    {
        int sum = 0;
        for (unsigned long i = pos; i < primes->size(); i++)
        {
            sum = sum + primes->at(i);
            if (sum == num)
            {
                seq_count++;
                break;
            }
            if (sum > num)
                break;
        }
        pos++;
        start = primes->at(pos);
        if (start > num)
            break;
    }

    return seq_count;
}
