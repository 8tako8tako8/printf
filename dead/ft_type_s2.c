
#include "ft_printf.h"


void	ft_putzero_s(t_fmt *fmt, int len, int *count)
{
    int margin;

    margin = (fmt->width) - len;
    while(margin-- > 0)
        ft_count_putchar('0', count);
}

void    ft_puts_by_precision(t_fmt *fmt, int len, int *count)
{
    if ((fmt->flag) == 1)
    {
        ft_putspace_2s(fmt, len, count);
        ft_putstr_2s(fmt, len, count);
    }
    else if ((fmt->flag) == -1)
    {
        ft_putstr_2s(fmt, len, count);
        ft_putspace_2s(fmt, len, count);
    }
    else if ((fmt->flag) == 0)
    {
        ft_putzero_2s(fmt, len, count);
        ft_putstr_2s(fmt, len, count);
    }
}

void	ft_putspace_2s(t_fmt *fmt, int len, int *count)
{
    int margin;

    margin = 0;
    if (len > (fmt->precision))
        margin = (fmt->width) - (fmt->precision);
    else if (len <= (fmt->precision))
        margin = (fmt->width) - len;
    while(margin-- > 0)
        ft_count_putchar(' ', count);
}

void	ft_putstr_2s(t_fmt *fmt, int len, int *count)
{
    int strlen;
    char *s1;

    s1 = fmt->s;
    if ((fmt->precision) >= len)
        strlen = len;
    else
        strlen = fmt->precision;
    write(1, s1, strlen);
    *count += strlen;
}

void	ft_putzero_2s(t_fmt *fmt, int len, int *count)
{
    int margin;

    margin = 0;
    if (len > (fmt->precision))
        margin = (fmt->width) - (fmt->precision);
    else if (len <= (fmt->precision))
        margin = (fmt->width) - len;
    while(margin-- > 0)
        ft_count_putchar('0', count);
}