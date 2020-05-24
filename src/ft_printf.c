/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifontai </var/mail/vifontai>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 19:23:35 by vifontai          #+#    #+#             */
/*   Updated: 2020/05/24 19:23:36 by vifontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int		ft_printf(const char *format, ...)
{
	t_all a;

	a.str = (char *)format;
	init_all(&a);
	va_start(a.arg, format);
	parser(&a);
	va_end(a.arg);
	return (a.len);
}
