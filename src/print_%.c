#include "../include/printf.h"

void	write_percent(t_all *a)
{
	if (a->width_number > 1)
	{
		a->len += a->width_number;
		if (a->flag[MIN])
		{
			ft_putchar('%');
			a->width_number--;
			print_width(a);
		}
		else
		{
			a->width_number--;
			print_width(a);
			ft_putchar('%');
		}  
	}
	else
	{
		ft_putchar('%');
		a->len++;
	}
}
