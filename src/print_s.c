/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifontai </var/mail/vifontai>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 19:25:11 by vifontai          #+#    #+#             */
/*   Updated: 2020/05/24 19:25:12 by vifontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int		recup_info_length_string(t_all *a, int len)
{
	int cheat;

	cheat = 0;
	if (a->width_number >= a->prec_number)
		a->len += a->width_number;
	else if (a->prec_number > a->width_number && a->prec_number < len)
		a->len += a->prec_number;
	else
		a->len += len;
	if (a->prec_number > len)
		cheat = len;
	if (len >= a->prec_number)
		cheat = a->prec_number;
	return (cheat);
}

void	prec_and_width_string(t_all *a, char *str, int len)
{
	int i;
	int cheat;
	int tmp;

	tmp = len;
	i = -1;
	cheat = recup_info_length_string(a, len);
	if (a->flag[MIN])
	{
		if (a->prec_number < len)
			tmp = a->prec_number;
		while (i++ < a->prec_number - 1 && i < len)
			ft_putchar(str[i]);
		while (a->width_number-- > tmp)
			ft_putchar(' ');
	}
	else
	{
		while (a->width_number-- > cheat)
			ft_putchar(' ');
		if (a->prec_number < len)
			tmp = a->prec_number;
		while (i++ < a->prec_number - 1 && i < tmp)
			ft_putchar(str[i]);
	}
}

void	only_prec_string(t_all *a, char *str, int len)
{
	int i;

	i = -1;
	if (a->prec_number > len)
		a->len += len;
	else
		a->len += a->prec_number;
	while (i++ < a->prec_number - 1 && i < len)
		ft_putchar(str[i]);
}

void	only_width_string(t_all *a, char *str, int len)
{
	if (len >= a->width_number)
		a->len += len;
	else
		a->len += a->width_number;
	if (a->flag[MIN])
	{
		ft_putstr(str);
		while (a->width_number-- > len)
			ft_putchar(' ');
	}
	else
	{
		while (a->width_number-- > len)
			ft_putchar(' ');
		ft_putstr(str);
	}
}

void	write_s(t_all *a, char *vargs)
{
	int len;

	if (vargs == NULL)
		vargs = "(null)";
	len = ft_strlen(vargs);
	if (!(a->flag[PREC]) && !(a->flag[WIDTH]))
	{
		ft_putstr(vargs);
		a->len += len;
	}
	else if (!(a->flag[PREC]) && (a->flag[WIDTH]))
		only_width_string(a, vargs, len);
	else if (!(a->flag[WIDTH]) && (a->flag[PREC]))
		only_prec_string(a, vargs, len);
	else if (a->flag[PREC] && a->flag[WIDTH])
		prec_and_width_string(a, vargs, len);
}
