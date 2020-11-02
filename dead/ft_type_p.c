#include "ft_printf.h"

void	ft_get_type_p(const char **str, va_list *ap, t_fmt *fmt)
{
    fmt->p = (void *)va_arg(*ap, void *);
    (*str)++;
}

void	ft_output_p(t_fmt *fmt, int *count)
{
    char                address[17] = {};

    ft_hex_convert_p(fmt, address);
    if ((fmt->precision) == -1)
        ft_putp_not_by_precision(address, fmt, count);
    else if ((fmt->precision) != -1)
        ft_putp_by_precision(address, fmt, count);
}

void	ft_hex_convert_p(t_fmt *fmt, char *address)
{
    unsigned long long  addr;
    char                hex[16] = "0123456789abcdef";
    unsigned long long  j;

    addr = (unsigned long long)(fmt->p);
    j = 0;
    while (addr > 0)
    {
        j = addr % 16;
        addr = addr / 16;
        address[(fmt->digit)] = hex[j];
        (fmt->digit)++;
    }
}

void    ft_putp_not_by_precision(char *addr, t_fmt *fmt, int *count)
{
    if ((fmt->width) == -1)
        ft_putaddr_p(addr, fmt, count);
    else if ((fmt->width) != -1)
    {
        if ((fmt->flag) == 1)
        {
            ft_putspace_p(fmt, count);
            ft_putaddr_p(addr, fmt, count);
        }
        else if ((fmt->flag) == -1)
        {
            ft_putaddr_p(addr, fmt, count);
            ft_putspace_p(fmt, count);
        }
    }
}

void	ft_putaddr_p(char *address, t_fmt *fmt, int *count)
{
    int digit1;

    digit1 = fmt->digit;
    *count += 2 + digit1; 
    write(1, "0x", 2);
    while (digit1 - 1 >= 0)
    {
        write(1, &address[digit1 - 1], 1);
        digit1--;
    }
}