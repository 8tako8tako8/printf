#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int ft_width_max_d(int width, int precision, int digit, int d)
{
    int width_max;

    if (digit >= precision)
        width_max = width - digit;
    else
        width_max = width - precision;
    if (d < 0)
        width_max--;
    return (width_max);
}

int	ft_isdigit(int c)//libft
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putspace_d(int width, int precision, int digit, int d, int *count)
{
    int margin;

    margin = ft_width_max_d(width, precision, digit, d);
    while(margin-- > 0)
    {
        ft_putchar(' ');
        (*count)++;
    }
}

void ft_putnbr_d(int n, int *count)
{
	unsigned int	nbr;

	nbr = n;
	if (n < 0)
	{
		ft_putchar('-');
        (*count)++;
		nbr = -n;
	}
	if (nbr >= 10)
		ft_putnbr_d(nbr / 10, count);
	ft_putchar(nbr % 10 + '0');
    (*count)++;
}

void ft_putnbr_2d(int d, int precision, int digit, int *count)
{
    int             margin;
    unsigned int	nbr;
    int             sign;

    sign = 1;
    if (d < 0)
    {
        ft_putchar('-');
        (*count)++;
        sign *= -1;
    }
    margin = precision - digit;
    while (margin-- > 0)
    {
        ft_putchar('0');
        (*count)++;
    }
	nbr = sign * d;
	if (nbr >= 10)
		ft_putnbr_d(nbr / 10, count);
	ft_putchar(nbr % 10 + '0');
    (*count)++;
}

void ft_putnbr_3d(int d, int precision, int digit, int *count)
{
    int             margin;
    unsigned int	nbr;
    int             sign;

    sign = 1;
    if (d < 0)
    {
        ft_putchar('-');
        (*count)++;
        sign *= -1;
    }
    margin = precision - digit;
    while (margin-- > 0)
    {
        ft_putchar('0');
        (*count)++;
    }
	nbr = sign * d;
	if (nbr >= 10)
		ft_putnbr_d(nbr / 10, count);
	ft_putchar(nbr % 10 + '0');
    (*count)++;
}

void ft_putnbr_4d(int d, int width, int digit, int *count)
{
    int             margin;
    unsigned int	nbr;
    int             sign;

    sign = 1;
    if (d < 0)
    {
        ft_putchar('-');
        (*count)++;
        sign *= -1;
    }
    if (sign == -1)
        margin = width - digit - 1;
    else
        margin = width - digit;
    while (margin-- > 0)
    {
        ft_putchar('0');
        (*count)++;
    }
	nbr = sign * d;
	if (nbr >= 10)
		ft_putnbr_d(nbr / 10, count);
	ft_putchar(nbr % 10 + '0');
    (*count)++;
}

int ft_atoi_d(const char ****str)
{
	long long		number;
	int				i;

    number = 0;
    i = 0;
    while (ft_isdigit(****str))
	{
		number = number * 10;
        number += ****str - '0';
		(***str)++;
    }
    return (number);
}

char ft_get_type_c(const char ***str, va_list *ap)
{
    unsigned char c;
    
    c = (unsigned char)va_arg(*ap, int);
    (**str)++;
    return (c);
}

int ft_get_type_d(const char ***str, va_list *ap, int *digit)
{
    int d;
    int tmp;

    d = (int)va_arg(*ap, int);
    tmp = d;
    while (tmp != 0)
    {
        tmp = tmp / 10;
        (*digit)++;
    } 
    (**str)++;
    return (d);
}

void ft_putspace_nbr_d(int width, int precision, int digit, int d, int *count)
{
    ft_putspace_d(width, precision, digit, d, count);
    ft_putnbr_3d(d, precision, digit, count);
}

void ft_putnbr_space_d(int width, int precision, int digit, int d, int *count)
{
    ft_putnbr_3d(d, precision, digit, count);
    ft_putspace_d(width, precision, digit, d, count);
}

void ft_putspace_c(int width, int *count)
{
    while (((width--) - 1) > 0)
    {
        ft_putchar(' ');
        (*count)++;
    }
}

void ft_output_c(int flag, int width, unsigned char c, int *count)
{
    if (width == 1)
    {
        ft_putchar(c);
        (*count)++;
    }
    else if (width > 1)
    {
        if (flag == 1)
        {
            ft_putspace_c(width, count);
            ft_putchar(c);
            (*count)++; 
        }
        else if (flag == -1)
        {
            ft_putchar(c);
            (*count)++;
            ft_putspace_c(width, count);
        }
    }
}

void ft_output_d(int flag, int width, int precision, int digit, int d, int *count)
{
    if (width == -1 && precision == 0 && d == 0)
        ft_putchar('\0');
    else if (digit >= width && digit >= precision)
        ft_putnbr_d(d, count);
    else if (precision > digit && precision >= width)
        ft_putnbr_2d(d, precision, digit, count);
    else if (width > digit && width > precision)
    {
        if (flag == 1)
            ft_putspace_nbr_d(width, precision, digit, d, count);
        else if (flag == -1)
            ft_putnbr_space_d(width, precision, digit, d, count);
        else if (flag == 0)
        {
            if (precision != -1)
                ft_putspace_nbr_d(width, precision, digit, d, count);
            else
                ft_putnbr_4d(d, width, digit, count);
        }
    }
}

char *ft_get_type_s(const char ***str, va_list *ap)
{
    char *s;
    
    s = (char *)va_arg(*ap, char *);
    (**str)++;
    return (s);
}

void *ft_get_type_p(const char ***str, va_list *ap)
{
    void *p;

    p = (void *)va_arg(*ap, void *);
    (**str)++;
    return (p);    
}

int ft_get_precision(const char ***str, va_list *ap)
{
    int precision;

    precision = -1;
    if (***str == '.')
    {
        (**str)++;// .を飛ばす。
        if (('1' <= ***str) && (***str <= '9'))
            precision = ft_atoi_d(&str);
        else if (***str == '0')
        {
            precision = 0;
            (**str)++;
        }
        else if (***str == '*')// *の時
        {
            precision = (int)va_arg(*ap, int);
            if (precision < 0)
                precision = -1;
            (**str)++;
        }
    }
    return (precision);
}

int ft_get_width(const char ***str, va_list *ap, int *flag)
{
    int width;

    width = -1;
    if (('1' <= ***str) && (***str <= '9'))
            width = ft_atoi_d(&str);
    else if (***str == '*')
    {
        width = (int)va_arg(*ap, int);
        if (width < 0)
        {
            *flag = -1;
            width *= -1;
        }
        (**str)++;
    }
    return (width);
}

int ft_get_flag(const char ***str)
{
    int flag;

    flag = 1;
    (**str)++;// %を飛ばす。
    if (***str == '0')
    {
        flag = 0;
        (**str)++;
        if (***str == '-')
            (**str)++;
    }
    else if (***str == '-')
    {
        flag = -1;
        (**str)++;
        if (***str == '0')
            (**str)++;
    }
    else if (***str == '%')
    {
        flag = 2;
        (**str)++;
    }
    return (flag);
}

void ft_putspace_s(int width, int len, int *count)
{
    int margin;

    margin = width - len;
    while(margin-- > 0)
    {
        ft_putchar(' ');
        (*count)++;
    }
}

void ft_putspace_2s(int width, int precision, int len, int *count)
{
    int margin;

    if (len > precision)
        margin = width - precision;
    else if (len <= precision)
        margin = width - len;
    while(margin-- > 0)
    {
        ft_putchar(' ');
        (*count)++;
    }
}

void ft_putstr_s(char *s, int len, int *count)
{
    write(1, s, len);
    (*count)++;
}

void ft_putstr_2s(char *s, int precision, int len, int *count)
{
    int strlen;

    if (precision >= len)
        strlen = len;
    else if (precision < len)
        strlen = precision;
    write(1, s, strlen);
    (*count)++;
}

void ft_output_s(int flag, int width, int precision, char *s, int *count)
{
    size_t      len;

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
        }
    }
    else if (precision != -1)
    {
        if (len >= width)
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
        }
        else if (width > len)
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
        }
    }
}

char *ft_hex_convert_p(void *p, int *i)
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
    (*i)--;
    p_address = address;
    return (p_address);
}

void ft_putaddr_p(char *address, int digit, int *count)
{
    *count += 2 + digit + 1; 
    write(1, "0x", 2);
    while (digit >= 0)
    {
        write(1, &address[digit], 1);
        digit--;
    }
}

void ft_putspace_p(int width, int digit, int *count)
{
    int margin;

    margin = width - digit - 3;
    while(margin-- > 0)
    {
        ft_putchar(' ');
        (*count)++;
    }
}

void ft_output_p(int flag, int width, void *p, int *count)
{
    int     digit;
    char    *address;

    digit = 0;
    address = ft_hex_convert_p(p, &digit);
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

void ft_putnbr_u(unsigned int n, int *count)
{
	unsigned int	nbr;

	nbr = n;
	if (nbr >= 10)
		ft_putnbr_d(nbr / 10, count);
	ft_putchar(nbr % 10 + '0');
    (*count)++;
}

void ft_putnbr_2u(unsigned int u, int precision, int digit, int *count)
{
    int             margin;
    unsigned int	nbr;

    nbr = u;
    margin = precision - digit;
    while (margin-- > 0)
    {
        ft_putchar('0');
        (*count)++;
    }
	if (nbr >= 10)
		ft_putnbr_u(nbr / 10, count);
	ft_putchar(nbr % 10 + '0');
    (*count)++;
}

void ft_putnbr_3u(unsigned int u, int precision, int digit, int *count)
{
    int             margin;
    unsigned int	nbr;

	nbr = u;
    margin = precision - digit;
    while (margin-- > 0)
    {
        ft_putchar('0');
        (*count)++;
    }
	if (nbr >= 10)
		ft_putnbr_u(nbr / 10, count);
	ft_putchar(nbr % 10 + '0');
    (*count)++;
}

void ft_putnbr_4u(unsigned int u, int width, int digit, int *count)
{
    int             margin;
    unsigned int	nbr;

	nbr = u;
    margin = width - digit;
    while (margin-- > 0)
    {
        ft_putchar('0');
        (*count)++;
    }
	if (nbr >= 10)
		ft_putnbr_d(nbr / 10, count);
	ft_putchar(nbr % 10 + '0');
    (*count)++;
}

int ft_width_max_u(int width, int precision, int digit, unsigned int u)
{
    int width_max;

    if (digit >= precision)
        width_max = width - digit;
    else
        width_max = width - precision;
    return (width_max);
}

void ft_putspace_u(int width, int precision, int digit, unsigned int u, int *count)
{
    int margin;

    margin = ft_width_max_u(width, precision, digit, u);
    while(margin-- > 0)
    {
        ft_putchar(' ');
        (*count)++;
    }
}

void ft_putspace_nbr_u(int width, int precision, int digit, unsigned int u, int *count)
{
    ft_putspace_u(width, precision, digit, u, count);
    ft_putnbr_3u(u, precision, digit, count);
}

void ft_putnbr_space_u(int width, int precision, int digit, unsigned int u, int *count)
{
    ft_putnbr_3u(u, precision, digit, count);
    ft_putspace_u(width, precision, digit, u, count);
}

void ft_output_u(int flag, int width, int precision, int digit, unsigned int u, int *count)
{
    if (width == -1 && precision == 0 && u == 0)
        ft_putchar('\0');
    else if (digit >= width && digit >= precision)
        ft_putnbr_u(u, count);
    else if (precision > digit && precision >= width)
        ft_putnbr_2u(u, precision, digit, count);
    else if (width > digit && width > precision)
    {
        if (flag == 1)
            ft_putspace_nbr_u(width, precision, digit, u, count);
        else if (flag == -1)
            ft_putnbr_space_u(width, precision, digit, u, count);
        else if (flag == 0)
        {
            if (precision != -1)
                ft_putspace_nbr_u(width, precision, digit, u, count);
            else
                ft_putnbr_4u(u, width, digit, count);
        }
    }
}

unsigned int ft_get_type_u(const char ***str, va_list *ap, int *digit)
{
    unsigned int u;
    unsigned int tmp;

    u = (unsigned int)va_arg(*ap, unsigned int);
    tmp = u;
    while (tmp != 0)
    {
        tmp = tmp / 10;
        (*digit)++;
    } 
    (**str)++;
    return (u);
}

unsigned int ft_get_type_x(const char ***str, va_list *ap)
{
    unsigned int x;

    x = (unsigned int)va_arg(*ap, unsigned int);
    (**str)++;
    return (x);
}

void ft_hex_convert_x(unsigned int x, int *i, char **hex_cvt)
{
    unsigned int        y;
    char                hex[16] = "0123456789abcdef";
    int                 j;

    y = x;
    j = 0;
    while (y > 0)
    {
        j = y % 16;
        y = y / 16;
        (*hex_cvt)[*i] = hex[j];
        //printf("--%d,%c--\n", *i, hex[j]);
        (*i)++;
    }
    (*i)--;
    //printf("===%s===\n", *hex_cvt);
}

void ft_putnbr_x(char **hex_cvt, int digit, int *count)
{
    //printf("!!%s!!%d!!\n", *hex_cvt, digit);
    *count += digit + 1;
    while (digit >= 0)
    {
        write(1, *hex_cvt + digit, 1);
        //printf("<<%c>>\n", *(*hex_cvt + digit));
        digit--;
    }
}

void ft_putnbr_2x(char **hex_cvt, int precision, int digit, int *count)
{
    int             margin;

    margin = precision - digit - 1;
    while (margin-- > 0)
    {
        ft_putchar('0');
        (*count)++;
    }
	ft_putnbr_x(hex_cvt, digit, count);
}

int ft_width_max_x(int width, int precision, int digit)
{
    int width_max;

    if (digit >= precision)
        width_max = width - digit;
    else
        width_max = width - precision;
    return (width_max);
}

void ft_putspace_x(int width, int precision, int digit, int *count)
{
    int margin;

    margin = ft_width_max_x(width, precision, digit + 1);
    while(margin-- > 0)
    {
        ft_putchar(' ');
        (*count)++;
    }
}

void ft_putspace_nbr_x(int width, int precision, int digit, char **hex_cvt, int *count)
{
    ft_putspace_x(width, precision, digit, count);
    ft_putnbr_2x(hex_cvt, precision, digit, count);
}

void ft_putnbr_space_x(int width, int precision, int digit, char **hex_cvt, int *count)
{
    ft_putnbr_2x(hex_cvt, precision, digit, count);
    ft_putspace_x(width, precision, digit, count);
}

void ft_output_x(int flag, int width, int precision, unsigned int x, int *count)
{
    int     digit;
    char    hex_cvt[17];
    char    *p_hex_cvt;

    digit = 0;
    p_hex_cvt = hex_cvt;
    ft_hex_convert_x(x, &digit, &p_hex_cvt);
    //printf("++%s++%d++\n", p_hex_cvt, digit);
    if (width == -1 && precision == 0 && x == 0)
        ft_putchar('\0');
    else if (digit >= width && digit >= precision)
        ft_putnbr_x(&p_hex_cvt, digit, count);
    else if (precision > digit && precision >= width)
        ft_putnbr_2x(&p_hex_cvt, precision, digit, count);
    else if (width > digit && width > precision)
    {
        if (flag == 1)
            ft_putspace_nbr_x(width, precision, digit, &p_hex_cvt, count);
        else if (flag == -1)
            ft_putnbr_space_x(width, precision, digit, &p_hex_cvt, count);
        else if (flag == 0)
        {
            if (precision != -1)
                ft_putspace_nbr_x(width, precision, digit, &p_hex_cvt, count);
            else
                ft_putnbr_2x(&p_hex_cvt, width, digit, count);
        }
    }
}

void ft_hex_convert_X(unsigned int x, int *i, char **hex_cvt)
{
    unsigned int        y;
    char                hex[16] = "0123456789ABCDEF";
    int                 j;

    y = x;
    j = 0;
    while (y > 0)
    {
        j = y % 16;
        y = y / 16;
        (*hex_cvt)[*i] = hex[j];
        //printf("--%d,%c--\n", *i, hex[j]);
        (*i)++;
    }
    (*i)--;
    //printf("===%s===\n", *hex_cvt);
}

void ft_output_X(int flag, int width, int precision, unsigned int x, int *count)
{
    int     digit;
    char    hex_cvt[17];
    char    *p_hex_cvt;

    digit = 0;
    p_hex_cvt = hex_cvt;
    ft_hex_convert_X(x, &digit, &p_hex_cvt);
    //printf("++%s++%d++\n", p_hex_cvt, digit);
    if (width == -1 && precision == 0 && x == 0)
        ft_putchar('\0');
    else if (digit >= width && digit >= precision)
        ft_putnbr_x(&p_hex_cvt, digit, count);
    else if (precision > digit && precision >= width)
        ft_putnbr_2x(&p_hex_cvt, precision, digit, count);
    else if (width > digit && width > precision)
    {
        if (flag == 1)
            ft_putspace_nbr_x(width, precision, digit, &p_hex_cvt, count);
        else if (flag == -1)
            ft_putnbr_space_x(width, precision, digit, &p_hex_cvt, count);
        else if (flag == 0)
        {
            if (precision != -1)
                ft_putspace_nbr_x(width, precision, digit, &p_hex_cvt, count);
            else
                ft_putnbr_2x(&p_hex_cvt, width, digit, count);
        }
    }
}

void ft_input(const char **str, va_list *ap, int *count)
{
    int             flag;
    int             width;
    int             precision;
    int             d;
    int             digit_du;
    unsigned int    u;
    unsigned char   c;
    char            *s;
    void            *p;
    unsigned int    x;

    digit_du = 0;
    //printf("%s\n", *str);
    flag = ft_get_flag(&str);//フラグ
    //printf("%s\n", *str);
    if (flag != 2)
    {
        width = ft_get_width(&str, ap, &flag);//フィールド幅
        //printf("%s\n", *str);
        precision = ft_get_precision(&str, ap);//精度
        if (**str == 'd' || **str == 'i')
        {
            d = ft_get_type_d(&str, ap, &digit_du);
            ft_output_d(flag, width, precision, digit_du, d, count);    
        }
        else if (**str == 'u')
        {
            u = ft_get_type_u(&str, ap, &digit_du);
            ft_output_u(flag, width, precision, digit_du, u, count);
        }
        else if (**str == 'c')
        {
            c = ft_get_type_c(&str, ap);
            ft_output_c(flag, width, c, count);
        }
        else if (**str == 's')
        {
            s = ft_get_type_s(&str, ap);
            ft_output_s(flag, width, precision, s, count);
        }
        else if (**str == 'p')
        {
            p = ft_get_type_p(&str, ap);
            ft_output_p(flag, width, p, count);
        }
        else if (**str == 'x')
        {
            x = ft_get_type_x(&str, ap);
            ft_output_x(flag, width, precision, x, count);
        }
        else if (**str == 'X')
        {
            x = ft_get_type_x(&str, ap);
            ft_output_X(flag, width, precision, x, count);
        }
    }
    else
        ft_putchar('%');
    //printf("flag:%d, width:%d, precision:%d, d:%u, digit:%d\n", flag, width, precision, u, digit_du);
}

void ft_printf_str(const char **start, const char **str, int *count)
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
            ft_input(&str, &ap, &count);
    }
    va_end(ap);
    return (count);
}
 
int main()
{
    int  d = 1;
    char c = 'a';
    char s[] = "abc";
/*  printf("[%p]", &d);
    ft_printf("[%p]\n", &d);
    printf("[%p]", &c);
    ft_printf("[%p]\n", &c);
    printf("[%p]", &s);
    ft_printf("[%p]\n", &s);
    ft_printf("[%d]", 123); 
    printf("[%06d]\n", -123); */
    ft_printf("[%%][%%%5d][%-5.3d][%*.5X][%4.*x][%3c][%p][%15p][%-5s][%u]\n", 123, -11, 8, 98, 7, 32, c, &s, &d, s, 2147483647);
    printf("[%%][%%%5d][%-5.3d][%*.5X][%4.*x][%3c][%p][%15p][%-5s][%u]", 123, -11, 8, 98, 7, 32, c, &s, &d, s, 2147483647);
    /* ft_printf("[%5d]", -123);
    printf("[%5d]\n", -123);
    ft_printf("[%1d]", -123);
    printf("[%1d]\n", -123);
    ft_printf("[%.5d]", -123);
    printf("[%.5d]\n", -123);
    ft_printf("[%.1d]", -123);
    printf("[%.1d]\n", -123);
    ft_printf("[%*.2d]", 5, -123);
    printf("[%*.2d]\n", 5, -123);
    ft_printf("[%2.*d]", 5, -123);
    printf("[%2.*d]\n", 5, -123);
    ft_printf("[%3.3d]", -12345);
    printf("[%3.3d]\n", -12345);
    ft_printf("[%02.8d]", -123);
    printf("[%02.8d]\n", -123);
    ft_printf("[%-2.8d]", -123);
    printf("[%-2.8d]\n", -123);
    ft_printf("[%-8.4d]", -123);
    printf("[%-8.4d]\n", -123);
    ft_printf("[%-8.4d]", -12345);
    printf("[%-8.4d]\n", -12345);
    ft_printf("[%08.4d]", -123);
    printf("[%08.4d]\n", -123);
    ft_printf("[%.0d]\n", 0);
    printf("[%.0d]\n", 0);
    ft_printf("[%5.2s]", "abc");
    printf("[%5.2s]\n", "abc");
    ft_printf("[%5.4s]", "abc");
    printf("[%5.4s]\n", "abc");
    ft_printf("[%5.7s]", "abc");
    printf("[%5.7s]\n", "abc");
    ft_printf("[%2.2s]", "abc");
    printf("[%2.2s]\n", "abc");
    ft_printf("[%2.5s]", "abc");
    printf("[%2.5s]\n", "abc");
    ft_printf("[%.5s]", "abc");
    printf("[%.5s]\n", "abc");
    ft_printf("[%-5.2s]", "abc");
    printf("[%-5.2s]\n", "abc"); */
    /* ft_printf("[%u]", 2147483647);
    printf("[%u]\n", 2147483647);
    ft_printf("[%5u]", 2147483647);
    printf("[%5u]\n", 2147483647);
    ft_printf("[%1u]", 2147483647);
    printf("[%1u]\n", 2147483647);
    ft_printf("[%.12u]", 2147483647);
    printf("[%.12u]\n", 2147483647);
    ft_printf("[%.1u]", 2147483647);
    printf("[%.1u]\n", 2147483647);
    ft_printf("[%*.2u]", 5, 2147483647);
    printf("[%*.2u]\n", 5, 2147483647);
    ft_printf("[%2.*u]", 5, 2147483647);
    printf("[%2.*u]\n", 5, 2147483647);
    ft_printf("[%12.12u]", 2147483647);
    printf("[%12.12u]\n", 2147483647);
    ft_printf("[%02.12u]", 2147483647);
    printf("[%02.12u]\n", 2147483647);
    ft_printf("[%-2.12u]", 2147483647);
    printf("[%-2.12u]\n", 2147483647);
    ft_printf("[%-12.4u]", 2147483647);
    printf("[%-12.4u]\n", 2147483647);
    ft_printf("[%-12.4u]", 2147483647);
    printf("[%-12.4u]\n", 2147483647);
    ft_printf("[%012.4u]", 2147483647);
    printf("[%012.4u]\n", 2147483647);
    ft_printf("[%.0u]", 2147483647);
    printf("[%.0u]\n", 2147483647);  */  
    /* ft_printf("[%-.5x]", 1000);
    printf("[%-.5x]\n", 1000);
    ft_printf("[%x]", 1000);
    printf("[%x]\n", 1000);
    ft_printf("[%x]", 10000);
    printf("[%x]\n", 10000);
    ft_printf("[%5x]", 1000);
    printf("[%5x]\n", 1000);    
    ft_printf("[%2x]", 100);
    printf("[%2x]\n", 100);
    ft_printf("[%.5x]", 100);
    printf("[%.5x]\n", 100);
    ft_printf("[%.2x]", 100);
    printf("[%.2x]\n", 100);
    ft_printf("[%5.2x]", 100);
    printf("[%5.2x]\n", 100);        
    ft_printf("[%2.5x]", 100);
    printf("[%2.5x]\n", 100);    
    ft_printf("[%-5x]", 100);
    printf("[%-5x]\n", 100);    
    ft_printf("[%-.5x]", 100);
    printf("[%-.5x]\n", 100);
    ft_printf("[%-8.5x]", 100);
    printf("[%-8.5x]\n", 100); */
    //ft_printf("[%05x]", 100);
    //printf("[%05x]\n", 100);

    return (0);
}