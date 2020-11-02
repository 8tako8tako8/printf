
#include "ft_printf.h"

void	ft_output_null_p(t_fmt *fmt, int *count)
{
    if ((fmt->precision) == -1)
        ft_putnull_not_by_precision_p(fmt, count);
    else if ((fmt->precision) != -1)
        ft_putnull_by_precision_p(fmt, count);
}

void    ft_putnull_not_by_precision_p(t_fmt *fmt, int *count)
{
    if ((fmt->width) <= 3)
        ft_putnull_p(3, count);
    else if ((fmt->width) > 3)
    {
        if ((fmt->flag) == 1)
        {
            ft_putspace_null_p(fmt, count);
            ft_putnull_p(3, count);
        }
        else if ((fmt->flag) == -1)
        {
            ft_putnull_p(3, count);
            ft_putspace_null_p(fmt, count);
        }
        else if ((fmt->flag) == 0)
        {
            ft_putnull_p(3, count);
            ft_putzero_null_p(fmt, count);
        }
    }
}

void	ft_putnull_p(int len, int *count)
{
    char n[] = "0x0";

    write(1, n, len);
    *count += len;
}

void	ft_putspace_null_p(t_fmt *fmt, int *count)
{
    int margin;

    margin = (fmt->width) - 3;
    while(margin-- > 0)
        ft_count_putchar(' ', count);
}

void	ft_putzero_null_p(t_fmt *fmt, int *count)
{
    int margin;

    margin = (fmt->width) - 3;
    while(margin-- > 0)
        ft_count_putchar('0', count);
}