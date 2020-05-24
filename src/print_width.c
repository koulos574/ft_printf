/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifontai <marvin.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 19:25:51 by vifontai          #+#    #+#             */
/*   Updated: 2020/05/24 19:25:52 by vifontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
