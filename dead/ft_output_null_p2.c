#include "ft_printf.h"

void    ft_putnull_by_precision_p(t_fmt *fmt, int *count)
{
    if ((fmt->flag == 1) || (fmt->flag == 0))
    {
        ft_putspace_null_2p(fmt, count);
        ft_putnull_2p(2, fmt, count);
    }
    else if ((fmt->flag) == -1)
    {
        ft_putnull_2p(2, fmt, count);
        ft_putspace_null_2p(fmt, count);
    }   
}

void	ft_putspace_null_2p(t_fmt *fmt, int *count)
{
    int margin;

    margin = (fmt->width) - 2 - (fmt->precision);
    while(margin-- > 0)
        ft_count_putchar(' ', count);
}

void	ft_putnull_2p(int len, t_fmt *fmt, int *count)
{
    char n[] = "0x";
    int margin;

    write(1, n, len);
    *count += len;
    margin = fmt->precision;
    while(margin-- > 0)
        ft_count_putchar('0', count);
}