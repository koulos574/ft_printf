#include "../include/printf.h"

void    flags_check(t_all *a)
{
   int i;

   i = 0;
   while (a->all_flags[i] != '\0')
   { 
        while (a->all_flags[i] == a->str[a->i])
        {
            if (a->str[a->i] == '0' && a->i++)
                a->flag[ZERO] = 1;
            if (a->str[a->i] == '-' && a->i++)
                a->flag[MIN] = 1;
            i = 0;
        }
        i++;
    }
}