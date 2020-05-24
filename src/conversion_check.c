/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifontai <marvin.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 19:23:19 by vifontai          #+#    #+#             */
/*   Updated: 2020/05/24 19:23:20 by vifontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	conversion_check(t_all *a)
{
	int i;

	i = 0;
	while (a->all_conversions[i] != '\0')
	{
		if (a->all_conversions[i] == a->str[a->i])
			a->conversion = a->all_conversions[i];
		i++;
	}
}
