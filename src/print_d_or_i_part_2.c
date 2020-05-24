#include "../include/printf.h"

void    zero_width_no_prec_int(t_all *a)
{
    a->len += a->width_number;
    while (a->width_number-- > 0)
        ft_putchar(' ');
}

void    no_width_no_prec_int(t_all *a, int sign, char *mystr)
{
    a->len += ft_strlen(mystr);
    if (sign < 0)
    {
        ft_putchar('-');
        a->len += 1;
    }
    ft_putstr(mystr);
    if(ft_strcmp(mystr,"0"))
        free(mystr);
}

void    recup_info_length_int(t_all *a, int len)
{
    if (len >= a->width_number && len >= a->prec_number)
        a->len += len;
    else if (a->width_number >= len && a->width_number >= a->prec_number)
        a->len += a->width_number;
    else if (a->prec_number >= len && a->prec_number >= a->width_number)
        a->len += a->prec_number;
}