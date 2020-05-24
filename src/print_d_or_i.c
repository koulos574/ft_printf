#include "../include/printf.h"

void	prec_and_width_int_part2(t_all *a, char *str, int len, int sign)
{
	int i;
	i = a->prec_number;
	recup_info_length_int(a, len);
	if (a->prec_number < len)
		a->prec_number = len;
	if (sign < 0)
	{
		a->prec_number += 1;
		if (a->width_number <= len)
			a->len++;
	}
	while (a->width_number-- > a->prec_number)
		ft_putchar(' ');
	if (sign < 0)
		ft_putchar('-');
	while(i-- > len)
		ft_putchar('0');
	ft_putstr(str);
}

void	prec_and_width_int(t_all *a, char *str, int len, int sign)
{
	int i;

	i = a->prec_number;
	if (a->flag[MIN])
	{
		recup_info_length_int(a, len);
		if (sign < 0)
		{
			ft_putchar('-');
			a->prec_number++;
			if (a->width_number <= len)
				a->len++;
		}
		while(i-- > len)
			ft_putchar('0');
		ft_putstr(str);
		if (sign < 0 && a->prec_number <= len)
			len++;
		if (a->prec_number < len)
			a->prec_number = len;
		while (a->width_number-- > a->prec_number)
			ft_putchar(' ');
	}
	else
		prec_and_width_int_part2(a, str, len, sign);
	if (ft_strcmp(str,"0"))
		free(str);
}

void	only_prec_int(t_all *a, char *str, int len, int sign)
{

	if (sign < 0)
	{
		ft_putchar('-');
		a->len += 1;
	}
	if (a->prec_number > len)
		a->len += a->prec_number;
	else
		a->len += len;
	while (a->prec_number-- > len)
		ft_putchar('0');
	ft_putstr(str);
	if (ft_strcmp(str,"0"))
		free(str);
}

void	only_width_int(t_all *a, char *str, int len, int sign)
{

	if (a->flag[MIN])
	{
		if (sign < 0)
		{
			ft_putchar('-');
			len += 1;
		}
		if (a->width_number >= len)
			a->len += a->width_number;
		else
			a->len += len;
		ft_putstr(str);
		a->width_number -= len;
		print_width(a);
	}
	else
	{
		if (sign < 0) 
			len += 1;
		if (a->flag[ZERO] && sign < 0)
			ft_putchar('-');
		if (a->width_number >= len)
			a->len += a->width_number;
		else
			a->len += len;
		a->width_number -= len;
		print_width(a);
		if (sign < 0 && !(a->flag[ZERO]))
			ft_putchar('-');
		ft_putstr(str);
	}
	if (ft_strcmp(str,"0"))
		free(str);
}

void	write_d(t_all *a, int vargs)
{
	char *mystr;
	int sign;
	long n;

	n = vargs;
	sign = 0;
	if (n < 0)
	{
		sign = -1;
		n *= -1;
	}
	mystr = ft_itoa(n);
	if (vargs == 0 && a->prec_number == 0)
		zero_width_no_prec_int(a);
	else if (!(a->flag[PREC]) && !(a->flag[WIDTH]))
		no_width_no_prec_int(a, sign, mystr);
	else if (a->flag[WIDTH] && !(a->flag[PREC]))
		only_width_int(a, mystr, ft_strlen(mystr), sign);
	else if (a->flag[PREC] && !(a->flag[WIDTH]))
		only_prec_int(a, mystr, ft_strlen(mystr), sign);  
	else if (a->flag[PREC] && a->flag[WIDTH])
		prec_and_width_int(a, mystr, ft_strlen(mystr), sign);
}
