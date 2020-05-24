/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x_and_X_part_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifontai <marvin.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 19:26:30 by vifontai          #+#    #+#             */
/*   Updated: 2020/05/24 21:41:37 by vifontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	zero_width_no_prec_x(t_all *a)
{
	a->len += a->width_number;
	while (a->width_number-- > 0)
		ft_putchar(' ');
}

void	no_width_no_prec_x(t_all *a, char *mystr)
{
	a->len += ft_strlen(mystr);
	ft_putstr(mystr);
	if (ft_strcmp(mystr, "0"))
		free(mystr);
}
