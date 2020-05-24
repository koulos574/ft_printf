#include "../include/printf.h"



int     ft_printf(const char *format, ...)
{
    t_all a;

    a.str = (char *)format;
    init_all(&a);
    va_start(a.arg, format);
    parser(&a);
    va_end(a.arg);
    return (a.len);

}

// int     main(void)
// {
// printf("p0 :%-u:\n", -1);
// 	ft_printf("p0 :%-u:\n", -1);
// }
    /*
    ** check pour c dans dans les autres printf voir si 0 
    ** et prec doivent etre quand meme fait
    */

    // printf("p0 :%-u:\n", -1);
	// ft_printf("p0 :%-u:\n", -1);
    // printf("p6 :%05u:\n", -2);
    // ft_printf("p6 :%05u:\n", -2);
	// printf("p13 :%0.0u:\n", -3);
    // ft_printf("p13 :%0.0u:\n", -3);
    // printf("p22 :%.5u:\n", -10);
    // ft_printf("p22 :%.5u:\n", -10);
    // printf("p23 :%u:\n", -2147483647);
    // ft_printf("p23 :%u:\n", -2147483647);
    // printf("p0 :%.7u:\n", -10000);
    // ft_printf("p0 :%.7u:\n", -10000);
    // printf("st2 :%0u:\n",-4);
    // ft_printf("st2 :%0u:\n",-4);
    // printf("p12 :%-45.10u:\n", -190);
    // ft_printf("p12 :%-45.10u:\n", -190);
    // printf("st1 :%-20.15u:\n", -50);
    // ft_printf("st1 :%-20.15u:\n", -50);
    // printf("t2 :%-6.5u:\n", -10);
    // ft_printf("t2 :%-6.5u:\n", -10);
    // printf("p0 :%-u:\n", 45);
	// ft_printf("p0 :%-u:\n", 45);
    // printf("p6 :%05u:\n", 111);
    // ft_printf("p6 :%05u:\n", 111);
	// printf("p13 :%0.0u:\n", 190);
    // ft_printf("p13 :%0.0u:\n", 190);
    // printf("p22 :%.5u:\n", 272);
    // ft_printf("p22 :%.5u:\n", 272);
    // printf("p23 :%u:\n", 2147483647);
    // ft_printf("p23 :%u:\n", 2147483647);
    // printf("p0 :%.7u:\n", 10000);
    // ft_printf("p0 :%.7u:\n", 10000);
    // printf("st2 :%0u:\n",4);
    // ft_printf("st2 :%0u:\n",4);
    // printf("p12 :%-45.10u:\n", 190);
    // ft_printf("p12 :%-45.10u:\n", 190);
    // printf("|%-*.*u|\n", 5, 4, 2);
    // ft_printf("|%-*.*u|\n", 5, 4, 2);
    // printf("|%-*.u|\n", 5, 2);
    // ft_printf("|%-*.*u|\n", 4, 5, 2);
    // printf("st1 :%55.44u:\n", -5000);
    // ft_printf("st1 :%55.44u:\n", -5000); 
    // printf("t2 :%8.u:\n", -255);
    // ft_printf("t2 :%8.2u:\n", -255);  
    // printf("|%0*.u|\n", 5, -2);
    // ft_printf("|%0*.u|\n", 5, -2);
    // printf("st1 :%55.44u:\n", 5000);
    // ft_printf("st1 :%55.44u:\n", 5000); 
    // printf("t2 :%8.u:\n", 255);
    // ft_printf("t2 :%8.2u:\n", 255);  
    // printf("|%4.d|\n", -0);
    //ft_printf("|%45d|\n|%5d|\n|%5.4d|\n|%.5d|\n|%-5d|\n", -2147483648,-2147483648,-2147483648,-2147483648,-2147483648);


    // ft_printf("p0 :%45u:\n", );
    // printf("p0 :%45u:\n", 45);
    // ft_printf("p6 :%025.5u:\n", -111);
    // printf("p6 :%025.5u:\n", -111);
    // ft_printf("p12 :%-45.10d:\n", -190);
    // printf("p12 :%-45.10d:\n", -190);
    // ft_printf("p12 :%0.0d:\n", -190);
    // printf("p12 :%0.0d:\n", -190);
    // ft_printf("p22 :%-.5d:\n", -2372);
    // printf("p22 :%-.5d:\n", -2372);
    // ft_printf(":%d:\n", -2147483647);
    // printf(":%d:\n", -2147483647);
    // ft_printf("p0 :%.7d:\n", -10000);
    // printf("p0 :%.7d:\n", -10000);
    // ft_printf("st1 :%*.*d:\n", 10, 10, -50);
    // printf("st1 :%*.*d:\n", 10, 10, -50);
    // ft_printf("st2 :%0d:\n",-4);
    // printf("st2 :%0d:\n",-4);
    // ft_printf("|%*.*i|\n", 5, 4, -2);
    // printf("|%*.*i|\n", 5, 4, -2);
    // ft_printf("|%*.i|\n", 5, -2);
    // printf("|%*.i|\n", 5, -2);
    // ft_printf("|%*.*d|\n", 4, 5, -2147483648);
    // printf("|%*.*d|\n", 4, 5, -2147483648);

//no precision, a->flag[ZERO]

	// int a= 1433431;

	// ft_printf(":%0x:\n",a);
	// ft_printf(":%.2x:\n",a);
	// printf(":%043x:\n",a);
	// ft_printf(":%-42.6x:\n",a);
	// ft_printf(":%043.5x:\n",a);
    // printf("p0 :%-X:\n", 45);
	// ft_printf("p0 :%-X:\n", 45);
    // printf("p6 :%05x:\n", 111);
    // ft_printf("p6 :%05x:\n", 111);
	// printf("p13 :%0.0X:\n", 190);
    // ft_printf("p13 :%0.0X:\n", 190);
    // printf("p22 :%.5x: %d %%\n", 272,273);
    // ft_printf("p22 :%.5x: %d %%\n", 272,273);
    // printf("p23 :%x:\n", 2147483647);
    // ft_printf("p23 :%x:\n", 2147483647);
    // printf("p0 :%.7x:\n", 10000);
    // ft_printf("p0 :%.7x:\n", 10000);
    // printf("st2 :%0x:\n",4);
    // ft_printf("st2 :%0x:\n",4);
    // printf("p12 :%.0x:\n", 0);
    // ft_printf("p12 :%.0x:\n", 0);
    // printf("|%-*.*x|\n", 5, 4, 2);
    // ft_printf("|%-*.*x|\n", 5, 4, 2);
    // printf("|%-*.*x|\n", 4,5,44);
    // ft_printf("|%-*.*x|\n", 4, 5, 44);
//     int d = 0;
//     int e = 345543;
//     int f = 0;
//     int *g = &f;
//     char *str = "aze";
//     printf("number %d\n",ft_printf(":%-45.49%:\n"));
//     printf("number %d\n",printf(":%-45.49%:\n"));
// }

/*
recuperer direct sous un char 
unsi = (unsigned int)(4294967295 + 1 + unsi); l'avoir
direct en bon format


TEST PRINTF
https://github.com/rizkyario/42-ft_printf/blob/master/resources/test.txt
*/