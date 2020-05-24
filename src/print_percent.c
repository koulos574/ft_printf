/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_%.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifontai <marvin.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 19:24:16 by vifontai          #+#    #+#             */
/*   Updated: 2020/05/24 19:31:30 by vifontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
