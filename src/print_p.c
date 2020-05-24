/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifontai <marvin.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 19:24:55 by vifontai          #+#    #+#             */
/*   Updated: 2020/05/24 21:38:49 by vifontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void		zero_width_no_prec_p(t_all *a)
{
	if (a->width_number > 2)
		a->len += a->width_number;
	else
		a->len += 2;
	if (!(a->flag[MIN]))
		while (a->width_number-- > 2)
			ft_putchar(' ');
	ft_putchar('0');
	ft_putchar('x');
	while (a->width_number-- > 2)
		ft_putchar(' ');
}

void		only_width_p(t_all *a, char *str)
{
	int len;

	if (!(ft_strcmp(str, "0x0")))
		len = 3;
	else
		len = 14;
	if (a->width_number > len)
		a->len += a->width_number;
	if (len >= a->width_number)
		a->len += len;
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

void		write_p(t_all *a, unsigned long long p)
{
	char	*mystr;
	int		i;

	i = 1;
	mystr = ft_strjoin_free_s2("0x", ft_unsigned_base(p, 16));
	while (mystr[i++])
		mystr[i] = ft_tolower(mystr[i]);
	if (!(a->flag[PREC]) && !(a->flag[WIDTH]))
	{
		ft_putstr(mystr);
		a->len += ft_strlen(mystr);
		free(mystr);
	}
	else if (a->prec_number == 0 && !(ft_strcmp(mystr, "0x0")))
		zero_width_no_prec_p(a);
	else if (a->flag[WIDTH])
		only_width_p(a, mystr);
}
