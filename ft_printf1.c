#include "ft_printf.h"

int     ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

size_t  ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

//---------------libft----------------

void    ft_get_precision(const char **str, va_list *ap, t_fmt *fmt)
{
    fmt->precision = -1;
    if (**str == '.')
    {
        (*str)++;// .を飛ばす。
        fmt->precision = 0;
        if (('1' <= **str) && (**str <= '9'))
            fmt->precision = ft_atoi_d(str);
        else if (**str == '0')
        {
            (*str)++;
            while (**str == '0')
                (*str)++;
            if (('1' <= **str) && (**str <= '9'))
                fmt->precision = ft_atoi_d(str);
        }
        else if (**str == '*')// *の時
        {
            fmt->precision = (int)va_arg(*ap, int);
            if (fmt->precision < 0)
                fmt->precision = -1;
            (*str)++;
        }
    }
}

void    ft_get_width(const char **str, va_list *ap, t_fmt *fmt)
{
    fmt->width = -1;
    if (('1' <= **str) && (**str <= '9'))
            fmt->width = ft_atoi_d(str);
    else if (**str == '0' || **str == '-')
    {
        while (**str == '0' || **str == '-')
            (*str)++;
    }
    else if (**str == '*')
    {
        fmt->width = (int)va_arg(*ap, int);
        if (fmt->width < 0)
        {
            fmt->flag = -1;
            fmt->width *= -1;
        }
        (*str)++;
    }
}

void	ft_get_flag(const char **str, t_fmt *fmt)
{
    fmt->flag = 1;
    (*str)++;// %を飛ばす。
    if (**str == '0')
    {
        fmt->flag = 0;
        (*str)++;
        if (**str == '-')
        {
            (*str)++;
            fmt->flag = -1;
        }
    }
    else if (**str == '-')
    {
        fmt->flag = -1;
        (*str)++;
        if (**str == '0')
            (*str)++;
    }
    else if (**str == '%')
    {
        fmt->flag = 2;
        (*str)++;
    }
}

//---------------ft_get_format.c----------------

void    ft_count_putchar(char c, int *count)
{
    ft_putchar(c);
    (*count)++;
}

//---------------ft_printf_utils.c----------------

int     ft_width_max_d(t_fmt *fmt)
{
    int width_max;

    if ((fmt->digit) >= (fmt->precision))
        width_max = (fmt->width) - (fmt->digit);
    else
        width_max = (fmt->width) - (fmt->precision);
    if ((fmt->d) < 0)
        width_max--;
    return (width_max);
}

void	ft_putspace_d(t_fmt *fmt, int *count)
{
    int margin;
    if ((fmt->precision) == 0 && (fmt->d) == 0 && (fmt->flag) == -1)
        margin = ft_width_max_d(fmt) + 1;
    else
        margin = ft_width_max_d(fmt);
    while(margin-- > 0)
        ft_count_putchar(' ', count);
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

void	ft_putnbr_3d(t_fmt *fmt, int *count)
{
    int             margin;
    unsigned int	nbr;
    int             sign;

    if ((fmt->precision) == 0 && (fmt->d) == 0)
        return;
    else
    {
        sign = 1;
        if ((fmt->d) < 0)
        {
            ft_count_putchar('-', count);
            sign *= -1;
        }
        margin = (fmt->precision) - (fmt->digit);
        while (margin-- > 0)
            ft_count_putchar('0', count);
        nbr = sign * (fmt->d);
        if (nbr >= 10)
            ft_putnbr_d(nbr / 10, count);
        ft_count_putchar(nbr % 10 + '0', count);
    }
}

void	ft_putnbr_4d(t_fmt *fmt, int *count)
{
    int             margin;
    unsigned int	nbr;
    int             sign;

    sign = 1;
    if ((fmt->d) < 0)
    {
        ft_count_putchar('-', count);
        sign *= -1;
    }
    if (sign == -1)
        margin = (fmt->width) - (fmt->digit) - 1;
    else
        margin = (fmt->width) - (fmt->digit);
    while (margin-- > 0)
        ft_count_putchar('0', count);
	nbr = sign * (fmt->d);
	if (nbr >= 10)
		ft_putnbr_d(nbr / 10, count);
	ft_count_putchar(nbr % 10 + '0', count);
}

int     ft_atoi_d(const char **str)
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

void	ft_putspace_nbr_d(t_fmt *fmt, int *count)
{
    ft_putspace_d(fmt, count);
    if ((fmt->precision) != 0 || (fmt->d) != 0)
        ft_putnbr_3d(fmt, count);
    else
        ft_count_putchar(' ', count);
}

void	ft_putnbr_space_d(t_fmt *fmt, int *count)
{
    ft_putnbr_3d(fmt, count);
    ft_putspace_d(fmt, count);
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

//---------------ft_type_d.c----------------
//---------------ft_type_d2.c----------------
//---------------ft_type_d3.c----------------

void	ft_get_type_c(const char **str, va_list *ap, t_fmt *fmt)
{
    fmt->c = (unsigned char)va_arg(*ap, int);
    (*str)++;
}

void	ft_putspace_c(t_fmt *fmt, int *count)
{
    while ((((fmt->width)--) - 1) > 0)
        ft_count_putchar(' ', count);
}

void	ft_output_c(t_fmt *fmt, int *count)
{
    char    c1;

    c1 = (char)fmt->c;
    if (-1 <= (fmt->width) && (fmt->width) <= 1)
        ft_count_putchar(c1, count);
    else if ((fmt->width) > 1)
    {
        if ((fmt->flag) == 1)
        {
            ft_putspace_c(fmt, count);
            ft_count_putchar(c1, count);
        }
        else if ((fmt->flag) == -1)
        {
            ft_count_putchar(c1, count);
            ft_putspace_c(fmt, count);
        }
    }
}

//---------------ft_type_c.c----------------

void	ft_get_type_s(const char **str, va_list *ap, t_fmt *fmt)
{
    fmt->s = (char *)va_arg(*ap, char *);
    (*str)++;
}

void	ft_putzero_s(t_fmt *fmt, int len, int *count)
{
    int margin;

    margin = (fmt->width) - len;
    while(margin-- > 0)
        ft_count_putchar('0', count);
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

void	ft_putspace_s(t_fmt *fmt, int len, int *count)
{
    int margin;

    margin = (fmt->width) - len;
    while(margin-- > 0)
        ft_count_putchar(' ', count);
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

void	ft_putstr_s(t_fmt *fmt, int len, int *count)
{
    char    *s1;

    s1 = fmt->s;
    write(1, s1, len);
    *count += len;
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

void    ft_puts_not_by_precision(t_fmt *fmt, int len, int *count)
{
    if (len >= (fmt->width))
        ft_putstr_s(fmt, len, count);
    else if ((fmt->width) > len)
    {
        if ((fmt->flag) == 1)
        {
            ft_putspace_s(fmt, len, count);
            ft_putstr_s(fmt, len, count);
        }
        else if ((fmt->flag) == -1)
        {
            ft_putstr_s(fmt, len, count);
            ft_putspace_s(fmt, len, count);
        }
        else if ((fmt->flag) == 0)
        {
            ft_putzero_s(fmt, len, count);
            ft_putstr_s(fmt, len, count);
        }
    }
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

void	ft_output_s(t_fmt *fmt, int *count)
{
    int      len;

    len = ft_strlen(fmt->s);
    if ((fmt->precision) == -1)
        ft_puts_not_by_precision(fmt, len, count);
    else if ((fmt->precision) != -1)
        ft_puts_by_precision(fmt, len, count);
}

//---------------ft_type_s.c----------------
//---------------ft_type_s2.c----------------

void	ft_get_type_p(const char **str, va_list *ap, t_fmt *fmt)
{
    fmt->p = (void *)va_arg(*ap, void *);
    (*str)++;
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

void	ft_putspace_p(t_fmt *fmt, int *count)
{
    int margin;

    margin = (fmt->width) - (fmt->digit) - 2;
    while(margin-- > 0)
        ft_count_putchar(' ', count);
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

void	ft_output_p(t_fmt *fmt, int *count)
{
    char                address[17] = {};

    ft_hex_convert_p(fmt, address);
    if ((fmt->precision) == -1)
        ft_putp_not_by_precision(address, fmt, count);
    else if ((fmt->precision) != -1)
        ft_putp_by_precision(address, fmt, count);
}

//---------------ft_type_p.c----------------
//---------------ft_type_p2.c----------------

void    ft_get_type_u(const char **str, va_list *ap, t_fmt *fmt)
{
    unsigned int tmp;

    fmt->u = (unsigned int)va_arg(*ap, unsigned int);
    tmp = fmt->u;
    if (tmp == 0)
        (fmt->digit)++;
    while (tmp != 0)
    {
        tmp = tmp / 10;
        (fmt->digit)++;
    } 
    (*str)++;
}

void    ft_putnbr_u_sub(t_fmt *fmt, int *count)
{
    unsigned int     n;

    n = fmt->u;
    ft_putnbr_u(n, count);
}

void	ft_putnbr_u(unsigned int n, int *count)
{
	unsigned int	nbr;

	nbr = n;
	if (nbr >= 10)
		ft_putnbr_u(nbr / 10, count);
	ft_count_putchar(nbr % 10 + '0', count);
}

void	ft_putnbr_2u(t_fmt *fmt, int *count)
{
    int             margin;
    unsigned int	nbr;

    nbr = (fmt->u);
    margin = (fmt->precision) - (fmt->digit);
    while (margin-- > 0)
        ft_count_putchar('0', count);
	if (nbr >= 10)
		ft_putnbr_u(nbr / 10, count);
	ft_count_putchar(nbr % 10 + '0', count);
}

void	ft_putnbr_3u(t_fmt *fmt, int *count)
{
    int             margin;
    unsigned int	nbr;

    if ((fmt->precision) == 0 && (fmt->u) == 0)
        return;
    else
    {
        nbr = (fmt->u);
        margin = (fmt->precision) - (fmt->digit);
        while (margin-- > 0)
            ft_count_putchar('0', count);
        if (nbr >= 10)
            ft_putnbr_u(nbr / 10, count);
        ft_count_putchar(nbr % 10 + '0', count);
    }
}

void	ft_putnbr_4u(t_fmt *fmt, int *count)
{
    int             margin;
    unsigned int	nbr;

	nbr = (fmt->u);
    margin = (fmt->width) - (fmt->digit);
    while (margin-- > 0)
        ft_count_putchar('0', count);
	if (nbr >= 10)
		ft_putnbr_u(nbr / 10, count);
	ft_count_putchar(nbr % 10 + '0', count);
}

int	ft_width_max_u(t_fmt *fmt)
{
    int width_max;

    if ((fmt->digit) >= (fmt->precision))
        width_max = (fmt->width) - (fmt->digit);
    else
        width_max = (fmt->width) - (fmt->precision);
    return (width_max);
}

void	ft_putspace_u(t_fmt *fmt, int *count)
{
    int margin;

    if ((fmt->precision) == 0 && (fmt->u) == 0 && (fmt->flag) == -1)
        margin = ft_width_max_u(fmt) + 1;
    else
        margin = ft_width_max_u(fmt);
    while(margin-- > 0)
        ft_count_putchar(' ', count);
}

void	ft_putspace_nbr_u(t_fmt *fmt, int *count)
{
    ft_putspace_u(fmt, count);
    if ((fmt->precision) != 0 || (fmt->u) != 0)
        ft_putnbr_3u(fmt, count);
    else
        ft_count_putchar(' ', count);
}

void	ft_putnbr_space_u(t_fmt *fmt, int *count)
{
    ft_putnbr_3u(fmt, count);
    ft_putspace_u(fmt, count);
}

void	ft_output_u(t_fmt *fmt, int *count)
{
    if ((fmt->width) == -1 && (fmt->precision) == 0 && (fmt->u) == 0)
        return ;
    else if ((fmt->digit) >= (fmt->width) && (fmt->digit) >= (fmt->precision))
        ft_putnbr_u_sub(fmt, count);
    else if ((fmt->precision) > (fmt->digit) && (fmt->precision) >= (fmt->width))
        ft_putnbr_2u(fmt, count);
    else if ((fmt->width) > (fmt->digit) && (fmt->width) > (fmt->precision))
    {
        if ((fmt->flag) == 1)
            ft_putspace_nbr_u(fmt, count);
        else if ((fmt->flag) == -1)
            ft_putnbr_space_u(fmt, count);
        else if ((fmt->flag) == 0)
        {
            if ((fmt->precision) != -1)
                ft_putspace_nbr_u(fmt, count);
            else
                ft_putnbr_4u(fmt, count);
        }
    }
}

//---------------ft_type_u.c----------------
//---------------ft_type_u2.c----------------
//---------------ft_type_u3.c----------------


void    ft_get_type_x(const char **str, va_list *ap, t_fmt *fmt)
{
    fmt->x = (unsigned int)va_arg(*ap, unsigned int);
    (*str)++;
}

void	ft_hex_convert_x(t_fmt *fmt, char **hex_cvt)
{
    unsigned int        y;
    char                hex[16] = "0123456789abcdef";
    int                 j;

    y = fmt->x;
    j = 0;
    if (y == 0)
    {
        (*hex_cvt)[0] = hex[0];
        (fmt->digit)++;
    }
    while (y > 0)
    {
        j = y % 16;
        y = y / 16;
        (*hex_cvt)[fmt->digit] = hex[j];
        (fmt->digit)++;
    }
}

void	ft_putnbr_x(char **hex_cvt, t_fmt *fmt, int *count)
{
    int digit1;

    digit1 = fmt->digit;
    *count += digit1;
    while (digit1 - 1 >= 0)
    {
        write(1, *hex_cvt + digit1 - 1, 1);
        digit1--;
    }
}

void	ft_putnbr_2x(char **hex_cvt, t_fmt *fmt, int *count)
{
    int             margin;
    margin = (fmt->precision) - (fmt->digit);
    while (margin-- > 0)
        ft_count_putchar('0', count);
    ft_putnbr_x(hex_cvt, fmt, count);
}

void	ft_putnbr_3x(char **hex_cvt, t_fmt *fmt, int *count)
{
    int             margin;

    margin = (fmt->width) - (fmt->digit);
    while (margin-- > 0)
        ft_count_putchar('0', count);
    ft_putnbr_x(hex_cvt, fmt, count);
}

int	ft_width_max_x(t_fmt *fmt)
{
    int width_max;

    if ((fmt->digit) >= (fmt->precision))
        width_max = (fmt->width) - (fmt->digit);
    else
        width_max = (fmt->width) - (fmt->precision);
    return (width_max);
}

void	ft_putspace_x(t_fmt *fmt, int *count)
{
    int margin;

    margin = ft_width_max_x(fmt);
    while(margin-- > 0)
        ft_count_putchar(' ', count);
}

void	ft_putspace_2x(t_fmt *fmt, int *count)
{
    while ((fmt->width)-- > 0)
        ft_count_putchar(' ', count);
}

void	ft_putspace_nbr_x(t_fmt *fmt, char **hex_cvt, int *count)
{
    if ((fmt->precision) == 0 && (fmt->x) == 0)
        ft_putspace_2x(fmt, count);
    else
    {
        ft_putspace_x(fmt, count);
        ft_putnbr_2x(hex_cvt, fmt, count);
    }
}

void	ft_putnbr_space_x(t_fmt *fmt, char **hex_cvt, int *count)
{
    if ((fmt->precision) == 0 && (fmt->x) == 0)
        ft_putspace_2x(fmt, count);
    else
    {
        ft_putnbr_2x(hex_cvt, fmt, count);
        ft_putspace_x(fmt, count);
    }
}

void	ft_output_x(t_fmt *fmt, int *count)
{
    char    hex_cvt[17] = {};
    char    *p_hex_cvt;

    p_hex_cvt = hex_cvt;
    ft_hex_convert_x(fmt, &p_hex_cvt);
    if ((fmt->width) == -1 && (fmt->precision) == 0 && (fmt->x) == 0)
        return ;
    else if ((fmt->digit) >= (fmt->width) && (fmt->digit) >= (fmt->precision))
        ft_putnbr_x(&p_hex_cvt, fmt, count);
    else if ((fmt->precision) > (fmt->digit) && (fmt->precision) >= (fmt->width))
        ft_putnbr_2x(&p_hex_cvt, fmt, count);
    else if ((fmt->width) > (fmt->digit) && (fmt->width) > (fmt->precision))
    {
        if ((fmt->flag) == 1)
            ft_putspace_nbr_x(fmt, &p_hex_cvt, count);
        else if ((fmt->flag) == -1)
            ft_putnbr_space_x(fmt, &p_hex_cvt, count);
        else if ((fmt->flag) == 0)
        {
            if ((fmt->precision) != -1)
                ft_putspace_nbr_x(fmt, &p_hex_cvt, count);
            else
                ft_putnbr_3x(&p_hex_cvt, fmt, count);
        }
    }
}

void	ft_hex_convert_X(t_fmt *fmt, char **hex_cvt)
{
    unsigned int        y;
    char                hex[16] = "0123456789ABCDEF";
    int                 j;

    y = fmt->x;
    j = 0;
    if (y == 0)
    {
        (*hex_cvt)[0] = hex[0];
        (fmt->digit)++;
    }
    while (y > 0)
    {
        j = y % 16;
        y = y / 16;
        (*hex_cvt)[fmt->digit] = hex[j];
        (fmt->digit)++;
    }
}

void	ft_output_X(t_fmt *fmt, int *count)
{
    char    hex_cvt[17] = {};
    char    *p_hex_cvt;

    p_hex_cvt = hex_cvt;
    ft_hex_convert_X(fmt, &p_hex_cvt);
    if ((fmt->width) == -1 && (fmt->precision) == 0 && (fmt->x) == 0)
        return ;
    else if ((fmt->digit) >= (fmt->width) && (fmt->digit) >= (fmt->precision))
        ft_putnbr_x(&p_hex_cvt, fmt, count);
    else if ((fmt->precision) > (fmt->digit) && (fmt->precision) >= (fmt->width))
        ft_putnbr_2x(&p_hex_cvt, fmt, count);
    else if ((fmt->width) > (fmt->digit) && (fmt->width) > (fmt->precision))
    {
        if ((fmt->flag) == 1)
            ft_putspace_nbr_x(fmt, &p_hex_cvt, count);
        else if ((fmt->flag) == -1)
            ft_putnbr_space_x(fmt, &p_hex_cvt, count);
        else if ((fmt->flag) == 0)
        {
            if ((fmt->precision) != -1)
                ft_putspace_nbr_x(fmt, &p_hex_cvt, count);
            else
                ft_putnbr_3x(&p_hex_cvt, fmt, count);
        }
    }
}

//---------------ft_type_x.c----------------
//---------------ft_type_x2.c----------------
//---------------ft_type_x3.c----------------

void	ft_putzero_null_s(t_fmt *fmt, int *count)
{
    int margin;

    margin = (fmt->width) - 6;
    while(margin-- > 0)
        ft_count_putchar('0', count);
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

void	ft_putspace_null_s(t_fmt *fmt, int *count)
{
    int margin;

    margin = (fmt->width) - 6;
    while(margin-- > 0)
        ft_count_putchar(' ', count);
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

void	ft_putnull_s(int len, int *count)
{
    char n[] = "(null)";

    write(1, n, len);
    *count += len;
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

void    ft_output_null_s(t_fmt *fmt, int *count)
{
    if ((fmt->precision) == -1)
        ft_putnull_not_by_precision_s(fmt, count);
    else if ((fmt->precision) != -1)
        ft_putnull_by_precision_s(fmt, count);
}

//---------------ft_output_null_s.c----------------
//---------------ft_output_null_s2.c----------------

void	ft_putzero_null_p(t_fmt *fmt, int *count)
{
    int margin;

    margin = (fmt->width) - 3;
    while(margin-- > 0)
        ft_count_putchar('0', count);
}

void	ft_putspace_null_p(t_fmt *fmt, int *count)
{
    int margin;

    margin = (fmt->width) - 3;
    while(margin-- > 0)
        ft_count_putchar(' ', count);
}

void	ft_putspace_null_2p(t_fmt *fmt, int *count)
{
    int margin;

    margin = (fmt->width) - 2 - (fmt->precision);
    while(margin-- > 0)
        ft_count_putchar(' ', count);
}

void	ft_putnull_p(int len, int *count)
{
    char n[] = "0x0";

    write(1, n, len);
    *count += len;
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

void	ft_output_null_p(t_fmt *fmt, int *count)
{
    if ((fmt->precision) == -1)
        ft_putnull_not_by_precision_p(fmt, count);
    else if ((fmt->precision) != -1)
        ft_putnull_by_precision_p(fmt, count);
}

//---------------ft_output_null_p.c----------------
//---------------ft_output_null_p2.c----------------

void    ft_get_type_and_output_d(const char **str, va_list *ap, int *count, t_fmt *fmt)
{
    ft_get_type_d(str, ap, fmt);
    ft_output_d(fmt, count);
}

void    ft_get_type_and_output_u(const char **str, va_list *ap, int *count, t_fmt *fmt)
{
    ft_get_type_u(str, ap, fmt);
    ft_output_u(fmt, count);
}

void    ft_get_type_and_output_c(const char **str, va_list *ap, int *count, t_fmt *fmt)
{
    ft_get_type_c(str, ap, fmt);
    ft_output_c(fmt, count);
}

void    ft_get_type_and_output_s(const char **str, va_list *ap, int *count, t_fmt *fmt)
{
    ft_get_type_s(str, ap, fmt);
    if ((fmt->s) == NULL)
        ft_output_null(fmt, count);
    else
        ft_output_s(fmt, count);
}

void    ft_get_type_and_output_p(const char **str, va_list *ap, int *count, t_fmt *fmt)
{
    ft_get_type_p(str, ap, fmt);
    if ((fmt->p) == NULL)
        ft_output_null_p(fmt, count);
    else
        ft_output_p(fmt, count);
}

void    ft_get_type_and_output_xX(const char **str, va_list *ap, int *count, t_fmt *fmt)
{
    if (**str == 'x')
    {
        ft_get_type_x(str, ap, fmt);
        ft_output_x(fmt, count);
    }
    else if (**str == 'X')
    {
        ft_get_type_x(str, ap, fmt);
        ft_output_X(fmt, count);
    }    
}

//--------ft_get_type_and_output.c-----------
//--------ft_get_type_and_output2.c-----------

void    ft_output_pct(const char **str, t_fmt *fmt, int *count)
{
    if ((fmt->flag) == 1)
    {
        while ((fmt->width) - 1 > 0)
        {
            ft_count_putchar(' ', count);
            (fmt->width)--;
        }
        ft_count_putchar('%', count);
    }
    else if ((fmt->flag) == -1)
    {
        ft_count_putchar('%', count);
        while ((fmt->width) - 1 > 0)
        {
            ft_count_putchar(' ', count);
            (fmt->width)--;
        }
    }
    else if ((fmt->flag) == 0)
    {
        while ((fmt->width) - 1 > 0)
        {
            ft_count_putchar('0', count);
            (fmt->width)--;
        }
        ft_count_putchar('%', count);
    }
    (*str)++;
}

void    ft_init_fmt(t_fmt *fmt)
{
    fmt->flag = 1;
    fmt->width = -1;
    fmt->precision = -1;
    fmt->s = NULL;
    fmt->p = NULL;
    fmt->digit = 0;
}

void	ft_input(const char **str, va_list *ap, int *count, t_fmt *fmt)
{
    ft_init_fmt(fmt);
    ft_get_flag(str, fmt);//フラグ
    if ((fmt->flag) == 2)
        ft_count_putchar('%', count);
    else
    {
        ft_get_width(str, ap, fmt);
        if (**str == '%')
            ft_output_pct(str, fmt, count);
        else
        {
            ft_get_precision(str, ap, fmt);
            if (**str == 'd' || **str == 'i')
                ft_get_type_and_output_d(str, ap, count, fmt);
            else if (**str == 'u')
                ft_get_type_and_output_u(str, ap, count, fmt);
            else if (**str == 'c')
                ft_get_type_and_output_c(str, ap, count, fmt);
            else if (**str == 's')
                ft_get_type_and_output_s(str, ap, count, fmt);
            else if (**str == 'p')
                ft_get_type_and_output_p(str, ap, count, fmt);
            else if (**str == 'x' || **str == 'X')
                ft_get_type_and_output_xX(str, ap, count, fmt);
        }
        //printf("flag:%d, width:%d, precision:%d\n", fmt->flag, fmt->width, fmt->precision);
    }
}

void	ft_printf_str(const char **start, const char **str, int *count)
{
    while (**str != '%' && **str)
        (*str)++;
    write(1, *start, *str - *start);
    *count += *str - *start;
}

int     ft_printf(const char *str, ...)
{
    va_list     ap;
    const char  *start;
    t_fmt       fmt;
    int         count;

    count = 0;    
    va_start(ap, str);
    if (str == NULL)
        count = -1;
    while (count >= 0 && *str)
    {
        start = str;
        if (*str != '%')
            ft_printf_str(&start, &str, &count);
        else
            ft_input(&str, &ap, &count, &fmt);
    }
    va_end(ap);
    return (count);
}
//--------ft_printf.c-----------