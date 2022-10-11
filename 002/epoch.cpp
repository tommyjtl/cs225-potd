#include "epoch.h"
#include <stdint.h>
#include <stdio.h>
/* Your code here! */

int hours(time_t t)
{
    return (intmax_t)t / 3600;
}

int days(time_t t)
{
    return (int)((intmax_t)t / 3600 / 24);
}

int years(time_t t)
{
    return (int)((intmax_t)t / 3600 / 24 / 365);
}