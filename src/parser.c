#include "../include/printf.h"

void    parser(t_all *a)
{
    while (a->str[a->i])
    { 
        if (a->str[a->i] == '%')
        {
            refresh(a);
            letsee(a);
        }
        else
        {
            ft_putchar(a->str[a->i]);
            a->len += 1;
        }
        a->i++;
    }
}