/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifontai </var/mail/vifontai>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 19:24:01 by vifontai          #+#    #+#             */
/*   Updated: 2020/05/24 19:30:48 by vifontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	parser(t_all *a)
{
	while (a->str[a->i])
	{
		if (a->str[a->i] == '%')
		{
			refresh(a);
			letsee(a);
		}
		else
		{
			ft_putchar(a->str[a->i]);
			a->len += 1;
		}
		a->i++;
	}
}
