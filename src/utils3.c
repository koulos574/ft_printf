/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifontai <marvin.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 19:26:59 by vifontai          #+#    #+#             */
/*   Updated: 2020/05/24 19:27:00 by vifontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

static int		lengthofnu(unsigned int n)
{
	int		j;

	if (n == 0)
		return (1);
	j = 0;
	if (n < 0)
	{
		n = -n;
		j++;
	}
	while (n != 0)
	{
		j++;
		n = n / 10;
	}
	return (j++);
}

char			*ft_itoa_uint(unsigned int n)
{
	long	long_n;
	long	j;
	char	*str;

	long_n = n;
	j = lengthofnu(n);
	if (long_n == 0)
		return ("0");
	if (!(str = (char *)malloc(sizeof(char) * j + 1)))
		return (0);
	j = 0;
	while (long_n > 0)
	{
		str[j++] = long_n % 10 + '0';
		long_n /= 10;
	}
	str[j] = '\0';
	return (reverse(str));
}
