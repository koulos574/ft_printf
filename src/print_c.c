/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifontai <marvin.42.fr>		            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 19:24:26 by vifontai          #+#    #+#             */
/*   Updated: 2020/05/24 19:24:27 by vifontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	write_c(t_all *a, char vargs)
{
	if (a->width_number > 1)
	{
		a->len += a->width_number;
		if (a->flag[MIN])
		{
			ft_putchar(vargs);
			while (a->width_number-- > 1)
				ft_putchar(' ');
		}
		else
		{
			while (a->width_number-- > 1)
				ft_putchar(' ');
			ft_putchar(vargs);
		}
	}
	else
	{
		ft_putchar(vargs);
		a->len++;
	}
}
