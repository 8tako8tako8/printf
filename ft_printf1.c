#include "ft_printf.h"

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

int	ft_width_max_d(t_fmt *fmt)
{
    int width_max;

    if ((fmt->digit_du) >= (fmt->precision))
        width_max = (fmt->width) - (fmt->digit_du);
    else
        width_max = (fmt->width) - (fmt->precision);
    if ((fmt->d) < 0)
        width_max--;
    return (width_max);
}

int	ft_isdigit(int c)
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

void    ft_count_putchar(char c, int *count)
{
    ft_putchar(c);
    (*count)++;
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
    margin = fmt->precision - fmt->digit_du;
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
        margin = (fmt->precision) - (fmt->digit_du);
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
        margin = (fmt->width) - (fmt->digit_du) - 1;
    else
        margin = (fmt->width) - (fmt->digit_du);
    while (margin-- > 0)
        ft_count_putchar('0', count);
	nbr = sign * (fmt->d);
	if (nbr >= 10)
		ft_putnbr_d(nbr / 10, count);
	ft_count_putchar(nbr % 10 + '0', count);
}

int ft_atoi_d(const char **str)
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
        (fmt->digit_du)++;
    while (tmp != 0)
    {
        tmp = tmp / 10;
        (fmt->digit_du)++;
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
    else if ((fmt->digit_du) >= (fmt->width) && (fmt->digit_du) >= (fmt->precision))
        ft_putnbr_d_sub(fmt, count);
    else if ((fmt->precision) > (fmt->digit_du) && (fmt->precision) >= (fmt->width))
        ft_putnbr_2d(fmt, count);
    else if ((fmt->width) > (fmt->digit_du) && (fmt->width) > (fmt->precision))
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

//---------------d----------------

/* char	ft_get_type_c(const char **str, va_list *ap)
{
    unsigned char c;
    
    c = (unsigned char)va_arg(*ap, int);
    (*str)++;
    return (c);
}

void	ft_putspace_c(int width, int *count)
{
    while (((width--) - 1) > 0)
        ft_count_putchar(' ', count);
}

void	ft_output_c(int flag, int width, unsigned char c, int *count)
{
    if (-1 <= width && width <= 1)
        ft_count_putchar((char)c, count);
    else if (width > 1)
    {
        if (flag == 1)
        {
            ft_putspace_c(width, count);
            ft_count_putchar((char)c, count);
        }
        else if (flag == -1)
        {
            ft_count_putchar((char)c, count);
            ft_putspace_c(width, count);
        }
    }
} */

//---------------c----------------

/* char	*ft_get_type_s(const char **str, va_list *ap)
{
    char *s;
    
    s = (char *)va_arg(*ap, char *);
    (*str)++;
    return (s);
}

void	ft_putzero_s(int width, int len, int *count)
{
    int margin;

    margin = width - len;
    while(margin-- > 0)
        ft_count_putchar('0', count);
}

void	ft_putzero_2s(int width, int precision, int len, int *count)
{
    int margin;

    margin = 0;
    if (len > precision)
        margin = width - precision;
    else if (len <= precision)
        margin = width - len;
    while(margin-- > 0)
        ft_count_putchar('0', count);
}

void	ft_putspace_s(int width, int len, int *count)
{
    int margin;

    margin = width - len;
    while(margin-- > 0)
        ft_count_putchar(' ', count);
}

void	ft_putspace_2s(int width, int precision, int len, int *count)
{
    int margin;

    margin = 0;
    if (len > precision)
        margin = width - precision;
    else if (len <= precision)
        margin = width - len;
    while(margin-- > 0)
        ft_count_putchar(' ', count);
}

void	ft_putstr_s(char *s, int len, int *count)
{
    write(1, s, len);
    *count += len;
}

void	ft_putstr_2s(char *s, int precision, int len, int *count)
{
    int strlen;

    if (precision >= len)
        strlen = len;
    else
        strlen = precision;
    write(1, s, strlen);
    *count += strlen;
}

void	ft_output_s(int flag, int width, int precision, char *s, int *count)
{
    int      len;

    len = ft_strlen(s);
    if (precision == -1)
    {
        if (len >= width)
            ft_putstr_s(s, len, count);
        else if (width > len)
        {
            if (flag == 1)
            {
                ft_putspace_s(width, len, count);
                ft_putstr_s(s, len, count);
            }
            else if (flag == -1)
            {
                ft_putstr_s(s, len, count);
                ft_putspace_s(width, len, count);
            }
            else if (flag == 0)
            {
                ft_putzero_s(width, len, count);
                ft_putstr_s(s, len, count);
            }
        }
    }
    else if (precision != -1)
    {
        if (flag == 1)
        {
            ft_putspace_2s(width, precision, len, count);
            ft_putstr_2s(s, precision, len, count);
        }
        else if (flag == -1)
        {
            ft_putstr_2s(s, precision, len, count);
            ft_putspace_2s(width, precision, len, count);
        }
        else if (flag == 0)
        {
            ft_putzero_2s(width, precision, len, count);
            ft_putstr_2s(s, precision, len, count);
        }
    }
} */

//---------------s----------------

/* void	*ft_get_type_p(const char **str, va_list *ap)
{
    void *p;

    p = (void *)va_arg(*ap, void *);
    (*str)++;
    return (p);    
}

char	*ft_hex_convert_p(void *p, int *i)
{
    unsigned long long  addr;
    char                hex[16] = "0123456789abcdef";
    char                address[17];
    char                *p_address;
    int                 j;

    addr = (unsigned long long)p;
    j = 0;
    while (addr > 0)
    {
        j = addr % 16;
        addr = addr / 16;
        address[*i] = hex[j];
        (*i)++;
    }
    p_address = address;
    return (p_address);
}

void	ft_putaddr_p(char *address, int digit, int *count)
{
    *count += 2 + digit; 
    write(1, "0x", 2);
    while (digit - 1 >= 0)
    {
        write(1, &address[digit - 1], 1);
        digit--;
    }
}

void	ft_putaddr_2p(char *address, int precision, int digit, int *count)
{
    int margin;

    write(1, "0x", 2);
    *count += 2;
    margin = precision - digit;
    while (margin-- > 0)
        ft_count_putchar('0', count);
    while (digit - 1 >= 0)
    {
        write(1, &address[digit - 1], 1);
        (*count)++;
        digit--;
    }
}

void	ft_putspace_p(int width, int digit, int *count)
{
    int margin;

    margin = width - digit - 2;
    while(margin-- > 0)
        ft_count_putchar(' ', count);
}

void	ft_putspace_2p(int width, int precision, int digit, int *count)
{
    int margin;

    if (digit + 2 >= precision)
        margin = width - digit - 2;
    else
        margin = width - precision - 2;    
    while(margin-- > 0)
        ft_count_putchar(' ', count);
}

void	ft_output_p(int flag, int width, int precision, void *p, int *count)
{
    int     digit;
    char    *address;

    digit = 0;
    address = ft_hex_convert_p(p, &digit);
    if (precision == -1)
    {
        if (width == -1)
            ft_putaddr_p(address, digit, count);
        else if (width != -1)
        {
            if (flag == 1)
            {
                ft_putspace_p(width, digit, count);
                ft_putaddr_p(address, digit, count);
            }
            else if (flag == -1)
            {
                ft_putaddr_p(address, digit, count);
                ft_putspace_p(width, digit, count);
            }
        }
    }
    if (precision != -1)
    {
        if (flag == 1 || flag == 0)
        {
            ft_putspace_2p(width, precision, digit, count);
            ft_putaddr_2p(address, precision, digit, count);
        }
        else if (flag == -1)
        {
            ft_putaddr_2p(address, precision, digit, count);
            ft_putspace_2p(width, precision, digit, count);
        }
    }
} */

//---------------p----------------

/* void	ft_putnbr_u(unsigned int n, int *count)
{
	unsigned int	nbr;

	nbr = n;
	if (nbr >= 10)
		ft_putnbr_u(nbr / 10, count);
	ft_count_putchar(nbr % 10 + '0', count);
}

void	ft_putnbr_2u(unsigned int u, int precision, int digit, int *count)
{
    int             margin;
    unsigned int	nbr;

    nbr = u;
    margin = precision - digit;
    while (margin-- > 0)
        ft_count_putchar('0', count);
	if (nbr >= 10)
		ft_putnbr_u(nbr / 10, count);
	ft_count_putchar(nbr % 10 + '0', count);
}

void	ft_putnbr_3u(unsigned int u, int precision, int digit, int *count)
{
    int             margin;
    unsigned int	nbr;

    if (precision == 0 && u == 0)
        return;
    else
    {
        nbr = u;
        margin = precision - digit;
        while (margin-- > 0)
            ft_count_putchar('0', count);
        if (nbr >= 10)
            ft_putnbr_u(nbr / 10, count);
        ft_count_putchar(nbr % 10 + '0', count);
    }
}

void	ft_putnbr_4u(unsigned int u, int width, int digit, int *count)
{
    int             margin;
    unsigned int	nbr;

	nbr = u;
    margin = width - digit;
    while (margin-- > 0)
        ft_count_putchar('0', count);
	if (nbr >= 10)
		ft_putnbr_u(nbr / 10, count);
	ft_count_putchar(nbr % 10 + '0', count);
}

int	ft_width_max_u(int width, int precision, int digit)
{
    int width_max;

    if (digit >= precision)
        width_max = width - digit;
    else
        width_max = width - precision;
    return (width_max);
}

void	ft_putspace_u(int flag, int width, int precision, int digit, unsigned int u, int *count)
{
    int margin;

    if (precision == 0 && u == 0 && flag == -1)
        margin = ft_width_max_u(width, precision, digit) + 1;
    else
        margin = ft_width_max_u(width, precision, digit);
    while(margin-- > 0)
        ft_count_putchar(' ', count);
}

void	ft_putspace_nbr_u(int flag, int width, int precision, int digit, unsigned int u, int *count)
{
    ft_putspace_u(flag, width, precision, digit, u, count);
    if (precision != 0 || u != 0)
        ft_putnbr_3u(u, precision, digit, count);
    else
        ft_count_putchar(' ', count);
}

void	ft_putnbr_space_u(int flag, int width, int precision, int digit, unsigned int u, int *count)
{
    ft_putnbr_3u(u, precision, digit, count);
    ft_putspace_u(flag, width, precision, digit, u, count);
}

void	ft_output_u(int flag, int width, int precision, int digit, unsigned int u, int *count)
{
    if (width == -1 && precision == 0 && u == 0)
        return ;
    else if (digit >= width && digit >= precision)
        ft_putnbr_u(u, count);
    else if (precision > digit && precision >= width)
        ft_putnbr_2u(u, precision, digit, count);
    else if (width > digit && width > precision)
    {
        if (flag == 1)
            ft_putspace_nbr_u(flag, width, precision, digit, u, count);
        else if (flag == -1)
            ft_putnbr_space_u(flag, width, precision, digit, u, count);
        else if (flag == 0)
        {
            if (precision != -1)
                ft_putspace_nbr_u(flag, width, precision, digit, u, count);
            else
                ft_putnbr_4u(u, width, digit, count);
        }
    }
}

unsigned int	ft_get_type_u(const char **str, va_list *ap, int *digit)
{
    unsigned int u;
    unsigned int tmp;

    u = (unsigned int)va_arg(*ap, unsigned int);
    tmp = u;
    if (u == 0)
        (*digit)++;
    while (tmp != 0)
    {
        tmp = tmp / 10;
        (*digit)++;
    } 
    (*str)++;
    return (u);
} */

//---------------u----------------

/* unsigned int	ft_get_type_x(const char **str, va_list *ap)
{
    unsigned int x;

    x = (unsigned int)va_arg(*ap, unsigned int);
    (*str)++;
    return (x);
}

void	ft_hex_convert_x(unsigned int x, int *i, char **hex_cvt)
{
    unsigned int        y;
    char                hex[16] = "0123456789abcdef";
    int                 j;

    y = x;
    j = 0;
    if (y == 0)
    {
        (*hex_cvt)[0] = hex[0];
        (*i)++;
    }
    while (y > 0)
    {
        j = y % 16;
        y = y / 16;
        (*hex_cvt)[*i] = hex[j];
        (*i)++;
    }
}

void	ft_putnbr_x(char **hex_cvt, int digit, int *count)
{
    *count += digit;
    while (digit - 1 >= 0)
    {
        write(1, *hex_cvt + digit - 1, 1);
        digit--;
    }
}

void	ft_putnbr_2x(char **hex_cvt, int precision, int digit, int *count)
{
    int             margin;

    margin = precision - digit;
    while (margin-- > 0)
        ft_count_putchar('0', count);
    ft_putnbr_x(hex_cvt, digit, count);
}

int	ft_width_max_x(int width, int precision, int digit)
{
    int width_max;

    if (digit >= precision)
        width_max = width - digit;
    else
        width_max = width - precision;
    return (width_max);
}

void	ft_putspace_x(int width, int precision, int digit, int *count)
{
    int margin;

    margin = ft_width_max_x(width, precision, digit);
    while(margin-- > 0)
        ft_count_putchar(' ', count);
}

void	ft_putspace_2x(int width, int *count)
{
    while (width-- > 0)
        ft_count_putchar(' ', count);
}

void	ft_putspace_nbr_x(int width, int precision, int digit, char **hex_cvt, unsigned int x, int *count)
{
    if (precision == 0 && x == 0)
        ft_putspace_2x(width, count);
    else
    {
        ft_putspace_x(width, precision, digit, count);
        ft_putnbr_2x(hex_cvt, precision, digit, count);
    }
}

void	ft_putnbr_space_x(int width, int precision, int digit, char **hex_cvt, unsigned int x, int *count)
{
    if (precision == 0 && x == 0)
        ft_putspace_2x(width, count);
    else
    {
        ft_putnbr_2x(hex_cvt, precision, digit, count);
        ft_putspace_x(width, precision, digit, count);
    }
}

void	ft_output_x(int flag, int width, int precision, unsigned int x, int *count)
{
    int     digit;
    char    hex_cvt[17] = {};
    char    *p_hex_cvt;

    digit = 0;
    p_hex_cvt = hex_cvt;
    ft_hex_convert_x(x, &digit, &p_hex_cvt);
    if (width == -1 && precision == 0 && x == 0)
        return ;
    else if (digit >= width && digit >= precision)
        ft_putnbr_x(&p_hex_cvt, digit, count);
    else if (precision > digit && precision >= width)
        ft_putnbr_2x(&p_hex_cvt, precision, digit, count);
    else if (width > digit && width > precision)
    {
        if (flag == 1)
            ft_putspace_nbr_x(width, precision, digit, &p_hex_cvt, x, count);
        else if (flag == -1)
            ft_putnbr_space_x(width, precision, digit, &p_hex_cvt, x, count);
        else if (flag == 0)
        {
            if (precision != -1)
                ft_putspace_nbr_x(width, precision, digit, &p_hex_cvt, x, count);
            else
                ft_putnbr_2x(&p_hex_cvt, width, digit, count);
        }
    }
}

void	ft_hex_convert_X(unsigned int x, int *i, char **hex_cvt)
{
    unsigned int        y;
    char                hex[16] = "0123456789ABCDEF";
    int                 j;

    y = x;
    j = 0;
    if (y == 0)
    {
        (*hex_cvt)[0] = hex[0];
        (*i)++;
    }    
    while (y > 0)
    {
        j = y % 16;
        y = y / 16;
        (*hex_cvt)[*i] = hex[j];
        (*i)++;
    }
}

void	ft_output_X(int flag, int width, int precision, unsigned int x, int *count)
{
    int     digit;
    char    hex_cvt[17] = {};
    char    *p_hex_cvt;

    digit = 0;
    p_hex_cvt = hex_cvt;
    ft_hex_convert_X(x, &digit, &p_hex_cvt);
    //printf("++%s++%d++\n", p_hex_cvt, digit);
    if (width == -1 && precision == 0 && x == 0)
        return ;
    else if (digit >= width && digit >= precision)
        ft_putnbr_x(&p_hex_cvt, digit, count);
    else if (precision > digit && precision >= width)
        ft_putnbr_2x(&p_hex_cvt, precision, digit, count);
    else if (width > digit && width > precision)
    {
        if (flag == 1)
            ft_putspace_nbr_x(width, precision, digit, &p_hex_cvt, x, count);
        else if (flag == -1)
            ft_putnbr_space_x(width, precision, digit, &p_hex_cvt, x, count);
        else if (flag == 0)
        {
            if (precision != -1)
                ft_putspace_nbr_x(width, precision, digit, &p_hex_cvt, x, count);
            else
                ft_putnbr_2x(&p_hex_cvt, width, digit, count);
        } 
    }
} */

//---------------xX----------------

void    ft_output_pct(const char **str, t_fmt *fmt, int *count)
{
    if (fmt->flag == 1)
    {
        while (fmt->width - 1 > 0)
        {
            ft_count_putchar(' ', count);
            fmt->width--;
        }
        ft_count_putchar('%', count);
    }
    else if (fmt->flag == -1)
    {
        ft_count_putchar('%', count);
        while (fmt->width - 1 > 0)
        {
            ft_count_putchar(' ', count);
            fmt->width--;
        }
    }
    else if (fmt->flag == 0)
    {
        while (fmt->width - 1 > 0)
        {
            ft_count_putchar('0', count);
            fmt->width--;
        }
        ft_count_putchar('%', count);
    }
    (*str)++;
}

//---------------%%----------------

/* void	ft_putzero_null(int width, int *count)
{
    int margin;

    margin = width - 6;
    while(margin-- > 0)
        ft_count_putchar('0', count);
}

void	ft_putzero_2null(int width, int precision, int *count)
{
    int margin;

    margin = 0;
    if (6 > precision)
        margin = width - precision;
    else if (6 <= precision)
        margin = width - 6;
    while(margin-- > 0)
        ft_count_putchar('0', count);
}

void	ft_putspace_null(int width, int *count)
{
    int margin;

    margin = width - 6;
    while(margin-- > 0)
        ft_count_putchar(' ', count);
}

void	ft_putspace_2null(int width, int precision, int *count)
{
    int margin;

    margin = 0;
    if (6 > precision)
        margin = width - precision;
    else if (6 <= precision)
        margin = width - 6;
    while(margin-- > 0)
        ft_count_putchar(' ', count);
}

void	ft_putnull(int len, int *count)
{
    char n[] = "(null)";

    write(1, n, len);
    *count += len;
}

void	ft_putnull_2(int precision, int *count)
{
    char n[] = "(null)";
    int strlen;

    if (precision >= 6)
        strlen = 6;
    else
        strlen = precision;
    write(1, n, strlen);
    *count += strlen;
}

void    ft_output_null(int flag, int width, int precision, int *count)
{
    if (precision == -1)
    {
        if (6 >= width)
            ft_putnull(6, count);
        else if (width > 6)
        {
            if (flag == 1)
            {
                ft_putspace_null(width, count);
                ft_putnull(6, count);
            }
            else if (flag == -1)
            {
                ft_putnull(6, count);
                ft_putspace_null(width, count);
            }
            else if (flag == 0)
            {
                ft_putzero_null(width, count);
                ft_putnull(6, count);                
            }
        }
    }
    else if (precision != -1)
    {
        if (flag == 1)
        {
            ft_putspace_2null(width, precision, count);
            ft_putnull_2(precision, count);
        }
        else if (flag == -1)
        {
            ft_putnull_2(precision, count);
            ft_putspace_2null(width, precision, count);
        }
        else if (flag == 0)
        {
            ft_putzero_2null(width, precision, count);
            ft_putnull_2(precision, count);            
        }
    }
} */

//---------------null_s----------------

/* void	ft_putzero_null_p(int width, int *count)
{
    int margin;

    margin = width - 3;
    while(margin-- > 0)
        ft_count_putchar('0', count);
}

void	ft_putspace_null_p(int width, int *count)
{
    int margin;

    margin = width - 3;
    while(margin-- > 0)
        ft_count_putchar(' ', count);
}

void	ft_putspace_null_2p(int width, int precision, int *count)
{
    int margin;

    margin = width - 2 - precision;
    while(margin-- > 0)
        ft_count_putchar(' ', count);
}

void	ft_putnull_p(int len, int *count)
{
    char n[] = "0x0";

    write(1, n, len);
    *count += len;
}

void	ft_putnull_2p(int len, int precision, int *count)
{
    char n[] = "0x";
    int margin;

    write(1, n, len);
    *count += len;
    margin = precision;
    while(margin-- > 0)
        ft_count_putchar('0', count);
}

void	ft_output_null_p(int flag, int width, int precision, int *count)
{
    if (precision == -1)
    {
        if (width <= 3)
            ft_putnull_p(3, count);
        else if (width > 3)
        {
            if (flag == 1)
            {
                ft_putspace_null_p(width, count);
                ft_putnull_p(3, count);
            }
            else if (flag == -1)
            {
                ft_putnull_p(3, count);
                ft_putspace_null_p(width, count);
            }
            else if (flag == 0)
            {
                ft_putnull_p(3, count);
                ft_putzero_null_p(width, count);
            }
        }
    }
    else if (precision != -1)
    {
        if (flag == 1 || flag == 0)
        {
            ft_putspace_null_2p(width, precision, count);
            ft_putnull_2p(2, precision, count);
        }
        else if (flag == -1)
        {
            ft_putnull_2p(2, precision, count);
            ft_putspace_null_2p(width, precision, count);
        }
    }
} */

//---------------null_p----------------

void    ft_init_fmt(t_fmt *fmt)
{
    fmt->flag = 1;
    fmt->width = -1;
    fmt->precision = -1;
    fmt->digit_du = 0;
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
            {
                ft_get_type_d(str, ap, fmt);
                ft_output_d(fmt, count);
            }
            /* else if (**str == 'u')
            {
                u = ft_get_type_u(str, ap, &digit_du);
                ft_output_u(flag, width, precision, digit_du, u, count);
            }
            else if (**str == 'c')
            {
                c = ft_get_type_c(str, ap);
                ft_output_c(flag, width, c, count);
            }
            else if (**str == 's')
            {
                s = ft_get_type_s(str, ap);
                if (s == NULL)
                    ft_output_null(flag, width, precision, count);
                else
                    ft_output_s(flag, width, precision, s, count);
            }
            else if (**str == 'p')
            {
                p = ft_get_type_p(str, ap);
                if (p == NULL)
                    ft_output_null_p(flag, width, precision, count);
                else
                    ft_output_p(flag, width, precision, p, count);
            }
            else if (**str == 'x')
            {
                x = ft_get_type_x(str, ap);
                ft_output_x(flag, width, precision, x, count);
            }
            else if (**str == 'X')
            {
                x = ft_get_type_x(str, ap);
                ft_output_X(flag, width, precision, x, count);
            } */
        }
        //printf("flag:%d, width:%d, precision:%d\n", flag, width, precision);
    }
}

void	ft_printf_str(const char **start, const char **str, int *count)
{
    while (**str != '%' && **str)
        (*str)++;
    write(1, *start, *str - *start);
    *count += *str - *start;
}

int ft_printf(const char *str, ...)
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