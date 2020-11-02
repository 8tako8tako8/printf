

#include "ft_printf.h"

void	ft_putspace_p(t_fmt *fmt, int *count)
{
    int margin;

    margin = (fmt->width) - (fmt->digit) - 2;
    while(margin-- > 0)
        ft_count_putchar(' ', count);
}

void    ft_putp_by_precision(char *addr, t_fmt *fmt, int *count)
{
    if ((fmt->flag == 1) || (fmt->flag == 0))
    {
        ft_putspace_2p(fmt, count);
        ft_putaddr_2p(addr, fmt, count);
    }
    else if ((fmt->flag) == -1)
    {
        ft_putaddr_2p(addr, fmt, count);
        ft_putspace_2p(fmt, count);
    }
}

void	ft_putspace_2p(t_fmt *fmt, int *count)
{
    int margin;

    if ((fmt->digit) + 2 >= (fmt->precision))
        margin = (fmt->width) - (fmt->digit) - 2;
    else
        margin = (fmt->width) - (fmt->precision) - 2;    
    while(margin-- > 0)
        ft_count_putchar(' ', count);
}

void	ft_putaddr_2p(char *address, t_fmt *fmt, int *count)
{
    int margin;
    int digit1;

    digit1 = fmt->digit;
    write(1, "0x", 2);
    *count += 2;
    margin = (fmt->precision) - digit1;
    while (margin-- > 0)
        ft_count_putchar('0', count);
    while (digit1 - 1 >= 0)
    {
        write(1, &address[digit1 - 1], 1);
        (*count)++;
        digit1--;
    }
}