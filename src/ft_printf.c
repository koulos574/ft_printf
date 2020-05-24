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
