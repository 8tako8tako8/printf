
#include "ft_printf.h"

void    ft_count_putchar(char c, int *count)
{
    ft_putchar(c);
    (*count)++;
}

int     ft_atoi_ex(const char **str)
{
	long long		number;
	int				i;

    number = 0;
    i = 0;
    while (ft_isdigit(**str))
	{
		number = number * 10;
        number += **str - '0';
		(*str)++;
    }
    return (number);
}