/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifontai <marvin.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 19:27:14 by vifontai          #+#    #+#             */
/*   Updated: 2020/05/24 19:27:15 by vifontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	width_check(t_all *a)
{
	if (a->str[a->i] == '*')
	{
		a->flag[WIDTH] = 1;
		a->flag[STAR] = 1;
		a->width_number = va_arg(a->arg, int);
		if (a->width_number < 0)
		{
			a->flag[MIN] = 1;
			a->width_number *= -1;
		}
		a->i++;
	}
	else
		while (ft_isdigit(a->str[a->i]))
		{
			a->flag[WIDTH] = 1;
			a->width_number = a->width_number * 10 + (a->str[a->i] - 48);
			a->i++;
		}
}
