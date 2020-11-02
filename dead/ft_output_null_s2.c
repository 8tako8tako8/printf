
#include "ft_printf.h"


void    ft_putnull_by_precision_s(t_fmt *fmt, int *count)
{
    if ((fmt->flag) == 1)
    {
        ft_putspace_2null_s(fmt, count);
        ft_putnull_2_s(fmt, count);
    }
    else if ((fmt->flag) == -1)
    {
        ft_putnull_2_s(fmt, count);
        ft_putspace_2null_s(fmt, count);
    }
    else if ((fmt->flag) == 0)
    {
        ft_putzero_2null_s(fmt, count);
        ft_putnull_2_s(fmt, count);            
    }    
}

void	ft_putspace_2null_s(t_fmt *fmt, int *count)
{
    int margin;

    margin = 0;
    if (6 > (fmt->precision))
        margin = (fmt->width) - (fmt->precision);
    else if (6 <= (fmt->precision))
        margin = (fmt->width) - 6;
    while(margin-- > 0)
        ft_count_putchar(' ', count);
}

void	ft_putnull_2_s(t_fmt *fmt, int *count)
{
    char n[] = "(null)";
    int len;

    if ((fmt->precision) >= 6)
        len = 6;
    else
        len = fmt->precision;
    write(1, n, len);
    *count += len;
}

void	ft_putzero_2null_s(t_fmt *fmt, int *count)
{
    int margin;

    margin = 0;
    if (6 > (fmt->precision))
        margin = (fmt->width) - (fmt->precision);
    else if (6 <= (fmt->precision))
        margin = (fmt->width) - 6;
    while(margin-- > 0)
        ft_count_putchar('0', count);
}