#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define FLAG_NUM 6



#include <stdio.h>
/*
** || prec || width || 0 || - || *
** ||  0   ||   1   || 2 || 3 || 4
*/

enum flags
{
  PREC = 0,
  WIDTH, // == WIDTH = 1
  ZERO,
  MIN,
  STAR,
};

typedef struct	printf_struct
{
  	char 	  *str;

    int 	  index;
    int     i;
    int     len;
	  va_list arg;

  	int 	  flag[FLAG_NUM];
    char    *all_flags;

    char    conversion;
    char    *all_conversions;

	  int 	  prec_number;
	  int		  width_number;
  
    int     char_count;
}           	t_all;


/*
** ft_printf.c
*/
int     ft_printf(const char *format, ...);

/*
** parser.c
*/
void    parser(t_all *a);

/*
** init_all
*/
void    init_all(t_all *a);
void    refresh(t_all *a);

/*
** letsee
*/
void    letsee(t_all *a);

/*
** flags_check
*/
void    flags_check(t_all *a);

/*
** conversion_check
*/
void    conversion_check(t_all *a);

/*
** width_check
*/
void    width_check(t_all *a);

/*
** precision_check
*/
void    precision_check(t_all *a);

/*
** allin
*/
void    allinwrite (t_all *a);

/*
** print_d_or_i
*/
void  write_d(t_all *a, int vargs);
void  only_width_int(t_all *a, char *str, int len, int sign);
void  only_prec_int(t_all *a, char *str, int len, int sign);
void  prec_and_width_int(t_all *a, char *mystr, int len, int sign);

/*
** print_d_or_i_part_2
*/
void    no_width_no_prec_int(t_all *a, int sign, char *mystr);
void    zero_width_no_prec_int(t_all *a);
void    recup_info_length_int(t_all *a, int len);

/*
** print_c
*/
void    write_c(t_all *a, char vargs);

/*
** print_s
*/
void    write_s(t_all *a, char *vargs);
void    only_width_string(t_all *a, char *str, int len);
void    only_prec_string(t_all *a, char *vargs, int len);
void    prec_and_width_string(t_all *a, char *vargs, int len);
int    recup_info_length_string(t_all *a, int len);

/*
** print_p
*/
void    write_p(t_all *a, unsigned long long p);

/*
** print_u
*/
void    write_u(t_all *a, unsigned int vargs);
void    no_width_no_prec_uint(t_all *a, char *mystr);
void    only_width_uint(t_all *a,char *mystr, int len);
void    only_prec_uint(t_all *a,char *mystr, int len);
void    prec_and_width_uint(t_all *a, char *mystr, int len);
void    prec_and_width_uint_part2(t_all *a, char *str, int len);
void    zero_width_no_prec_uint(t_all *a);

/*
** print_width
*/
void    print_width(t_all *a);
void    zero_width_no_prec_p(t_all *a);
void    only_width_p(t_all *a, char *str);

/*
** print_x_and_X
*/
void    write_x(t_all *a, unsigned int vargs, int maj);
void    zero_width_no_prec_x(t_all *a);
void    only_width_x(t_all *a, char *str, int len);
void    only_prec_x(t_all *a, char *str, int len);
void    prec_and_width_x(t_all *a, char *mystr, int len);

/*
** print_x_and_X_part_2
*/
void    no_width_no_prec_x(t_all *a, char *mystr);
void    zero_width_no_prec_x(t_all *a);

/*
** print_percent
*/
void    write_percent(t_all *a);


/*
** utils1
*/
int     ft_isdigit(char c);
void    ft_putchar(char z);
int     ft_strlen(char *str);
void    ft_putstr(char *str);
char	  *ft_strjoin_free_s2(char const *s1, char const *s2);

/*
** utils2
*/
char		      *reverse(char *str);
char			    *ft_itoa(long n);

/*
** utils 3
*/
char			    *ft_itoa_uint(unsigned int n);

/*
** utils 4
*/
char			  *ft_unsigned_base(unsigned long long nbr, int base);
int	        ft_strcmp(char *s1, char *s2);
int		      ft_tolower(int c);
int		      ft_tomaj(int c);

# endif