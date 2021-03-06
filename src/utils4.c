/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifontai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 19:27:08 by vifontai          #+#    #+#             */
/*   Updated: 2020/05/24 19:27:09 by vifontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

static char	*treat_base(unsigned long long i_save, int b, char *str, int c)
{
	while (i_save != 0)
	{
		if ((i_save % b) < 10)
			str[c - 1] = (i_save % b) + 48;
		else
			str[c - 1] = (i_save % b) + 55;
		i_save /= b;
		c--;
	}
	return (str);
}

char		*ft_unsigned_base(unsigned long long i, int base)
{
	char				*str;
	unsigned long long	i_save;
	int					count;

	str = 0;
	count = 0;
	i_save = i;
	if (i == 0)
		return ("0");
	while (i != 0)
	{
		i /= base;
		count++;
	}
	if (!(str = malloc(sizeof(char) * (count + 1))))
		return (0);
	str[count] = '\0';
	str = treat_base(i_save, base, str, count);
	return (str);
}

int			ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int			ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

int			ft_tomaj(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
