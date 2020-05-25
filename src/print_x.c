/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x_and_X.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifontai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 19:26:00 by vifontai          #+#    #+#             */
/*   Updated: 2020/05/24 19:26:22 by vifontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	prec_and_width_x_part2(t_all *a, char *str, int len)
{
	int i;
	int c;

	c = 0;
	i = a->prec_number;
	if (a->prec_number < len)
		a->prec_number = len;
	c = a->prec_number - a->width_number;
	if (a->keep_track_prec_neg)
		while (a->width_number-- > a->prec_number)
			if (a->flag[ZERO])
				ft_putchar('0');
			else
				ft_putchar(' ');
	else
		while (a->width_number-- > a->prec_number)
			if (a->flag[ZERO] && c++ > 0)
				ft_putchar('0');
			else
				ft_putchar(' ');
	while (i-- > len)
		ft_putchar('0');
	ft_putstr(str);
}

void	prec_and_width_x(t_all *a, char *str, int len)
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
		while (i-- > len)
			ft_putchar('0');
		ft_putstr(str);
		if (a->prec_number < len)
			a->prec_number = len;
		while (a->width_number-- > a->prec_number)
			ft_putchar(' ');
	}
	else
		prec_and_width_x_part2(a, str, len);
	if (ft_strcmp(str, "0"))
		free(str);
}

void	only_prec_x(t_all *a, char *str, int len)
{
	if (a->prec_number > len)
		a->len += a->prec_number;
	else
		a->len += len;
	while (a->prec_number-- > len)
		ft_putchar('0');
	ft_putstr(str);
	if (ft_strcmp(str, "0"))
		free(str);
}

void	only_width_x(t_all *a, char *str, int len)
{
	if (a->width_number > len)
		a->len += a->width_number;
	else
		a->len += len;
	if (a->keep_track_width_neg == 1)
			a->flag[ZERO] = 0;
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
	if (ft_strcmp(str, "0"))
		free(str);
}

void	write_x(t_all *a, unsigned int vargs, int min)
{
	char	*mystr;
	int		i;

	i = 0;
	mystr = ft_unsigned_base((unsigned long long)vargs, 16);
	if (min == 1)
		if (ft_strcmp(mystr, "0"))
			while (mystr[i] != '\0')
			{
				mystr[i] = ft_tolower(mystr[i]);
				i++;
			}
	if (mystr == NULL)
		mystr = "0";
	if (!(ft_strcmp(mystr, "0")) && a->prec_number == 0)
		zero_width_no_prec_x(a);
	else if (!(a->flag[PREC]) && !(a->flag[WIDTH]))
		no_width_no_prec_x(a, mystr);
	else if (a->flag[WIDTH] && !(a->flag[PREC]))
		only_width_x(a, mystr, ft_strlen(mystr));
	else if (a->flag[PREC] && !(a->flag[WIDTH]))
		only_prec_x(a, mystr, ft_strlen(mystr));
	else if (a->flag[PREC] && a->flag[WIDTH])
		prec_and_width_x(a, mystr, ft_strlen(mystr));
}
