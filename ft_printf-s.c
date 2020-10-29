#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/* int ft_width_max(int width, int precision, int digit, int d)
{
    int width_max;

    if (digit >= precision)
        width_max = width - digit;
    else
        width_max = width - precision;
    if (d < 0)
        width_max--;
    return (width_max);
} */

int		ft_isdigit(int c)//libft
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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/* void ft_putspace_d(int width, int precision, int digit, int d, int ***count)
{
    int margin;

    margin = ft_width_max(width, precision, digit, d);
    while(margin-- > 0)
    {
        ft_putchar(' ');
        (***count)++;
    }
} */

/* void	ft_putnbr_d(int n, int **count)
{
	unsigned int	nbr;

	nbr = n;
	if (n < 0)
	{
		ft_putchar('-');
        (**count)++;
		nbr = -n;
	}
	if (nbr >= 10)
		ft_putnbr_d(nbr / 10, count);
	ft_putchar(nbr % 10 + '0');
    (**count)++;
} */

/* void	ft_putnbr_2d(int d, int precision, int digit, int **count)
{
    int             margin;
    unsigned int	nbr;
    int             sign;

    sign = 1;
    if (d < 0)
    {
        ft_putchar('-');
        (**count)++;
        sign *= -1;
    }
    margin = precision - digit;
    while (margin-- > 0)
    {
        ft_putchar('0');
        (**count)++;
    }
	nbr = sign * d;
	if (nbr >= 10)
		ft_putnbr_d(nbr / 10, count);
	ft_putchar(nbr % 10 + '0');
    (**count)++;
} */

/* void	ft_putnbr_3d(int d, int precision, int digit, int ***count)
{
    int             margin;
    unsigned int	nbr;
    int             sign;

    sign = 1;
    if (d < 0)
    {
        ft_putchar('-');
        (***count)++;
        sign *= -1;
    }
    margin = precision - digit;
    while (margin-- > 0)
    {
        ft_putchar('0');
        (***count)++;
    }
	nbr = sign * d;
	if (nbr >= 10)
		ft_putnbr_d(nbr / 10, *count);
	ft_putchar(nbr % 10 + '0');
    (***count)++;
} */

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

/* char ft_get_type_c(const char ***str, va_list *ap)
{
    unsigned char c;
    
    c = (unsigned char)va_arg(*ap, int);
    (**str)++;
    return (c);
} */

/* int ft_get_type_d(const char ***str, va_list *ap, int *digit)
{
    int d;
    int tmp;

    d = 0;

    d = (int)va_arg(*ap, int);
    tmp = d;
    while (tmp != 0)
    {
        tmp = tmp / 10;
        (*digit)++;
    } 
    (**str)++;
    return (d);
} */

/* void ft_putspace_nbr_d(int width, int precision, int digit, int d, int **count)
{
    ft_putspace_d(width, precision, digit, d, &count);
    ft_putnbr_3d(d, precision, digit, &count);
} */

/* void ft_putnbr_space_d(int width, int precision, int digit, int d, int **count)
{
    ft_putnbr_3d(d, precision, digit, &count);
    ft_putspace_d(width, precision, digit, d, &count);
} */

/* void ft_putspace_c(int width, int *count)
{
    while (((width--) - 1) > 0)
    {
        ft_putchar(' ');
        (*count)++;
    }
} */

/* void ft_output_c(int flag, int width, unsigned char c, int *count)
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
} */

/* void ft_output_d(int flag, int width, int precision, int digit, int d, int *count)
{
    if (width == -1 && precision == 0 && d == 0)
        ft_putchar('\0');
    else if (digit >= width && digit >= precision)
        ft_putnbr_d(d, &count);
    else if (precision > digit && precision >= width)
        ft_putnbr_2d(d, precision, digit, &count);
    else if (width > digit && width > precision)
    {
        if (flag == 1)
            ft_putspace_nbr_d(width, precision, digit, d, &count);
        else if (flag == -1)
            ft_putnbr_space_d(width, precision, digit, d, &count);
        else if (flag == 0)
        {
            if (precision != 1)
                ft_putspace_nbr_d(width, precision, digit, d, &count);
            else
                ft_putspace_nbr_d(width, precision, digit, d, &count);
        }
    }
} */

char *ft_get_type_s(const char ***str, va_list *ap)
{
    char *s;
    
    s = (char *)va_arg(*ap, char *);
    (**str)++;
    return (s);
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

void ft_input(const char **str, va_list *ap, int *count)
{
    int             flag;
    int             width;
    int             precision;
    int             d;
    int             digit;
    unsigned char   c;
    char            *s;

    digit = 0;
    //printf("%s\n", *str);
    flag = ft_get_flag(&str);//フラグ
    //printf("%s\n", *str);
    width = ft_get_width(&str, ap, &flag);//フィールド幅
    //printf("%s\n", *str);
    precision = ft_get_precision(&str, ap);//精度
    /* if (**str == 'd')
    {
        d = ft_get_type_d(&str, ap, &digit);
        ft_output_d(flag, width, precision, digit, d, count);    
    } */
    /* else if (**str == 'c')
    {
        c = ft_get_type_c(&str, ap);
        ft_output_c(flag, width, c, count);
    } */
    if (**str == 's')
    {
        s = ft_get_type_s(&str, ap);
        ft_output_s(flag, width, precision, s, count);
    }
    //printf("flag:%d, width:%d, precision:%d, d:%d, digit:%d\n", flag, width, precision, d, digit);
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
    int d;
    /*ft_printf("[%d]", 123);
    printf("[%d]\n", 123);
    ft_printf("[%d]", -123);
    printf("[%d]\n", -123);
    ft_printf("[%5d]", -123);
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
    printf("[%.0d]\n", 0);*/
    ft_printf("[%5.2s]", "abc");
    printf("[%5.2s]\n", "abc");
    ft_printf("[%5.4s]", "abc");
    printf("[%5.4s]\n", "abc");
    ft_printf("[%5.7s]", "abc");
    printf("[%5.7s]\n", "abc");    //d = ft_printf("[%5.2s]", "abc");
    ft_printf("[%2.2s]", "abc");
    printf("[%2.2s]\n", "abc");    //printf("count: %d", d);
    ft_printf("[%2.5s]", "abc");
    printf("[%2.5s]\n", "abc");
    ft_printf("[%.5s]", "abc");
    printf("[%.5s]\n", "abc");
    ft_printf("[%-5.2s]", "abc");
    printf("[%-5.2s]\n", "abc");

    return (0);
}