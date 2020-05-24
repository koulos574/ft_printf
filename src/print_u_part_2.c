#include "../include/printf.h"

void	zero_width_no_prec_uint(t_all *a)
{
	a->len += a->width_number;
	while (a->width_number-- > 0)
		ft_putchar(' ');
}

void	no_width_no_prec_uint(t_all *a, char *mystr)
{
	a->len += ft_strlen(mystr);
	ft_putstr(mystr);
	free(mystr);
}
