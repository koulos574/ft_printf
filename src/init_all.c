#include "../include/printf.h"

void    init_all(t_all *a)
{
    a->i = 0;
    a->len = 0;
    a->all_conversions = "cspdiuxX%";
    a->all_flags = "-0";
}

void    refresh(t_all *a)
{
    a->flag[PREC] = 0;
    a->flag[WIDTH] = 0;
    a->flag[ZERO] = 0;
    a->flag[MIN] = 0;
    a->flag[STAR] = 0;
    a->prec_number = -1;
    a->width_number = 0;
    a->conversion = '\0';
}