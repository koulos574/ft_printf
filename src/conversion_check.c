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
