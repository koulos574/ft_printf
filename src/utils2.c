/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifontai <marvin.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 19:26:53 by vifontai          #+#    #+#             */
/*   Updated: 2020/05/24 19:26:55 by vifontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

char			*reverse(char *str)
{
	unsigned int	i;
	unsigned int	j;
	char			l;

	i = 0;
	j = 0;
	while (str[j])
		j++;
	j--;
	while (i < j)
	{
		l = str[i];
		str[i] = str[j];
		str[j] = l;
		i++;
		j--;
	}
	return (str);
}

static int		sign(long n)
{
	if (n < 0)
		return (1);
	return (0);
}

static int		lengthofn(long n)
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

char			*ft_itoa(long n)
{
	long	long_n;
	long	j;
	char	*str;

	long_n = n;
	j = lengthofn(n);
	if (long_n < 0)
		long_n = -long_n;
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
	if (sign(n) == 1)
		str[j++] = '-';
	str[j] = '\0';
	return (reverse(str));
}
