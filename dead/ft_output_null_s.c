
#include "ft_printf.h"


void    ft_output_null_s(t_fmt *fmt, int *count)
{
    if ((fmt->precision) == -1)
        ft_putnull_not_by_precision_s(fmt, count);
    else if ((fmt->precision) != -1)
        ft_putnull_by_precision_s(fmt, count);
}

void    ft_putnull_not_by_precision_s(t_fmt *fmt, int *count)
{
    if (6 >= (fmt->width))
        ft_putnull_s(6, count);
    else if ((fmt->width) > 6)
    {
        if ((fmt->flag) == 1)
        {
            ft_putspace_null_s(fmt, count);
            ft_putnull_s(6, count);
        }
        else if ((fmt->flag) == -1)
        {
            ft_putnull_s(6, count);
            ft_putspace_null_s(fmt, count);
        }
        else if ((fmt->flag) == 0)
        {
            ft_putzero_null_s(fmt, count);
            ft_putnull_s(6, count);                
        }
    }
}

void	ft_putnull_s(int len, int *count)
{
    char n[] = "(null)";

    write(1, n, len);
    *count += len;
}

void	ft_putspace_null_s(t_fmt *fmt, int *count)
{
    int margin;

    margin = (fmt->width) - 6;
    while(margin-- > 0)
        ft_count_putchar(' ', count);
}

void	ft_putzero_null_s(t_fmt *fmt, int *count)
{
    int margin;

    margin = (fmt->width) - 6;
    while(margin-- > 0)
        ft_count_putchar('0', count);
}