#include "../include/printf.h"

void	allinwrite(t_all *a)
{
	if (a->conversion == 'd' || a->conversion == 'i')
		write_d(a, va_arg(a->arg, int));
	else if (a->conversion == 'c')
		write_c(a, va_arg(a->arg, int));
	else if (a->conversion == 's')
		write_s(a, va_arg(a->arg, char *));
	else if (a->conversion == 'u')
		write_u(a, va_arg(a->arg, unsigned int));
	else if (a->conversion == 'p')
		write_p(a, va_arg(a->arg, unsigned long long));
	else if (a->conversion == 'x')
		write_x(a, va_arg(a->arg, unsigned int), 1);
	else if (a->conversion == 'X')
		write_x(a, va_arg(a->arg, unsigned int), 0);
	else if (a->conversion == '%')
		write_percent(a);
}
