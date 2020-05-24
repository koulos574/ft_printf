#include "../include/printf.h"

void	prec_and_width_uint_part2(t_all *a, char *str, int len)
{
	int i;

	i = a->prec_number;
	if (a->prec_number < len)
		a->prec_number = len;
	while (a->width_number-- > a->prec_number)
		ft_putchar(' ');
	while(i-- > len)
		ft_putchar('0');
	ft_putstr(str);

}

void	prec_and_width_uint(t_all *a, char *str, int len)
{
	int i;

	i = a->prec_number;
	if (len >= a->width_number && len >= a->prec_number)
		a->len += len;
	else if (a->width_number >= len && a->width_number >= a->prec_number)
		a->len += a->width_number;
	else if (a->prec_number >= len && a->prec_number >= a->width_number)
		a->len += a->prec_number;
	if (a->flag[MIN])
	{
		while(i-- > len)
			ft_putchar('0');
		ft_putstr(str);
		if (a->prec_number < len)
			a->prec_number = len;
		while (a->width_number-- > a->prec_number)
			ft_putchar(' ');
	}
	else
		prec_and_width_uint_part2(a, str, len);
	free(str);    
}

void	only_prec_uint(t_all *a, char *str, int len)
{
	if (len >= a->prec_number)
		a->len += len;
	else
		a->len += a->prec_number;
	while (a->prec_number-- > len)
		ft_putchar('0');
	ft_putstr(str);
	free(str);
}

void	only_width_uint(t_all *a, char *str, int len)
{
	if (len >= a->width_number)
		a->len += len;
	else
		a->len += a->width_number;

	if (a->flag[MIN])
	{
		ft_putstr(str);
		a->width_number -= len;
		print_width(a);
	}
	else
	{
		a->width_number -= len;
		print_width(a);
		ft_putstr(str);
	}
	free(str);
}


void	write_u(t_all *a, unsigned int vargs)
{
	char *mystr;

	mystr = ft_itoa_uint(vargs);
	if (vargs == 0 && a->prec_number == 0)
		zero_width_no_prec_uint(a);
	else if (!(a->flag[PREC]) && !(a->flag[WIDTH]))
		no_width_no_prec_uint(a, mystr);
	else if (a->flag[WIDTH] && !(a->flag[PREC]))
		only_width_uint(a, mystr, ft_strlen(mystr));
	else if (a->flag[PREC] && !(a->flag[WIDTH]))
		only_prec_uint(a, mystr, ft_strlen(mystr));
	else if (a->flag[PREC] && a->flag[WIDTH])
		prec_and_width_uint(a, mystr, ft_strlen(mystr));
}
