/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_or_i_part_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifontai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 19:24:46 by vifontai          #+#    #+#             */
/*   Updated: 2020/05/24 19:24:47 by vifontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	zero_width_no_prec_int(t_all *a)
{
	a->len += a->width_number;
	while (a->width_number-- > 0)
		ft_putchar(' ');
}

void	no_width_no_prec_int(t_all *a, int sign, char *mystr)
{
	a->len += ft_strlen(mystr);
	if (sign < 0)
	{
		ft_putchar('-');
		a->len += 1;
	}
	ft_putstr(mystr);
	if (ft_strcmp(mystr, "0"))
		free(mystr);
}

void	recup_info_length_int(t_all *a, int len)
{
	if (len >= a->width_number && len >= a->prec_number)
		a->len += len;
	else if (a->width_number >= len && a->width_number >= a->prec_number)
		a->len += a->width_number;
	else if (a->prec_number >= len && a->prec_number >= a->width_number)
		a->len += a->prec_number;
	if (a->prec_number < len)
		a->prec_number = len;
}

void	need_place_int(t_all *a, char *str, int len, int sign)
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

void	prec_and_width_int_part1(t_all *a, char *str, int len, int sign)
{
	int i;

	i = a->prec_number;
	recup_info_length_int(a, len);
	if (sign < 0)
	{
		ft_putchar('-');
		a->prec_number++;
		if (a->width_number <= len)
			a->len++;
		if (a->width_number > len && a->width_number < a->prec_number)
			a->len++;
	}
	while (i-- > len)
		ft_putchar('0');
	ft_putstr(str);
	if (sign < 0 && a->prec_number <= len)
		len++;
	if (a->prec_number < len)
		a->prec_number = len;
	while (a->width_number-- > a->prec_number)
		ft_putchar(' ');
}
