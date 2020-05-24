#include "../include/printf.h"

void	print_width(t_all *a)
{
	while (a->width_number > 0)
	{
		if (a->flag[ZERO])
			ft_putchar('0');
		else
			ft_putchar(' ');
		a->width_number = a->width_number - 1;
	}
}
