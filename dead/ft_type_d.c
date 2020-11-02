
#include "ft_printf.h"


void    ft_get_type_d(const char **str, va_list *ap, t_fmt *fmt)
{
    int tmp;

    fmt->d = (int)va_arg(*ap, int);
    tmp = fmt->d;
    if (fmt->d == 0)
        (fmt->digit)++;
    while (tmp != 0)
    {
        tmp = tmp / 10;
        (fmt->digit)++;
    }
    (*str)++;
}

void	ft_output_d(t_fmt *fmt, int *count)
{
    if ((fmt->width) == -1 && (fmt->precision) == 0 && (fmt->d) == 0)
        return ;
    else if ((fmt->digit) >= (fmt->width) && (fmt->digit) >= (fmt->precision))
        ft_putnbr_d_sub(fmt, count);
    else if ((fmt->precision) > (fmt->digit) && (fmt->precision) >= (fmt->width))
        ft_putnbr_2d(fmt, count);
    else if ((fmt->width) > (fmt->digit) && (fmt->width) > (fmt->precision))
    {
        if ((fmt->flag) == 1)
            ft_putspace_nbr_d(fmt, count);
        else if ((fmt->flag) == -1)
            ft_putnbr_space_d(fmt, count);
        else if ((fmt->flag) == 0)
        {
            if ((fmt->precision) != -1)
                ft_putspace_nbr_d(fmt, count);
            else
                ft_putnbr_4d(fmt, count);
        }
    }
}

void    ft_putnbr_d_sub(t_fmt *fmt, int *count)
{
    int     n;

    n = fmt->d;
    ft_putnbr_d(n, count);
}

void	ft_putnbr_d(int n, int *count)
{
	unsigned int	nbr;

	nbr = n;
	if (n < 0)
	{
		ft_count_putchar('-', count);
		nbr = -n;
	}
	if (nbr >= 10)
		ft_putnbr_d(nbr / 10, count);
	ft_count_putchar(nbr % 10 + '0', count);
}

void	ft_putnbr_2d(t_fmt *fmt, int *count)
{
    int             margin;
    unsigned int	nbr;
    int             sign;

    sign = 1;
    if (fmt->d < 0)
    {
        ft_count_putchar('-', count);
        sign *= -1;
    }
	nbr = sign * (fmt->d);
    margin = (fmt->precision) - (fmt->digit);
    while (margin-- > 0)
        ft_count_putchar('0', count);
	if (nbr >= 10)
		ft_putnbr_d(nbr / 10, count);
	ft_count_putchar(nbr % 10 + '0', count);
}