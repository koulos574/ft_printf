#include "../include/printf.h"

void    letsee(t_all *a)
{
    a->i++;
    flags_check(a);
    width_check(a);
    precision_check(a);
    conversion_check(a);
    allinwrite(a);
}