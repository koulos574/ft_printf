/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letsee.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifontai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 19:23:53 by vifontai          #+#    #+#             */
/*   Updated: 2020/05/24 19:23:55 by vifontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	letsee(t_all *a)
{
	a->i++;
	flags_check(a);
	width_check(a);
	precision_check(a);
	conversion_check(a);
	allinwrite(a);
}
