#include "../include/printf.h"

void    precision_check(t_all *a)
{
    if (a->str[a->i] == '.' && a->i++)
    {
        a->prec_number = 0;
        a->flag[PREC] = 1;
    }
    if (a->str[a->i] == '*')
    {
        a->flag[STAR] = 1;
        a->prec_number = va_arg(a->arg, int);
        a->i++;
    }
    else
        while (ft_isdigit(a->str[a->i]))
        {
            a->prec_number = a->prec_number * 10 + (a->str[a->i] - 48);
            a->i++;
        }
}