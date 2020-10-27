#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int ft_width_max(int width, int precision, int digit, int d)
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

int		ft_isdigit(int c)//libft
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)//libft
{
	size_t		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar_fd(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_fd(int n)
{
	unsigned int	nbr;

	nbr = n;
	if (n < 0)
	{
		ft_putchar_fd('-');
		nbr = -n;
	}
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10);
	ft_putchar_fd(nbr % 10 + '0');
}

void ft_putspace(int width, int precision, int digit, int d)
{
    int margin;

    margin = ft_width_max(width, precision, digit, d);
    while(margin-- > 0)
        ft_putchar_fd(' ');
}

void	ft_putnbr_ex(int d, int precision, int digit)
{
    int             margin;
    unsigned int	nbr;
    int             sign;

    sign = 1;
    if (d < 0)
    {
        ft_putchar_fd('-');
        sign *= -1;
    }
    margin = precision - digit;
    while (margin-- > 0)
        ft_putchar_fd('0');
	nbr = sign * d;
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10);
	ft_putchar_fd(nbr % 10 + '0');
}

int ft_atoi_ex(const char *str)
{
	long long		number;
	int				i;

    number = 0;
    i = 0;
    while (ft_isdigit(str[i]))
	{
		number = number * 10;
        number += str[i] - '0';
		i++;
    }
    return (number);
}

int ft_get_type(const char **str, va_list *ap, int *digit)
{
    int d;
    int tmp;

    d = 0;
    if (**str == 'd')
    {
        d = (int)va_arg(*ap, int);
        tmp = d;
        while (tmp != 0)
        {
            tmp = tmp / 10;
            (*digit)++;
        } 
        (*str)++;
    }
    return (d);
}

int ft_get_precision(const char **str, va_list *ap)
{
    int precision;

    precision = 1;
    if (**str == '.')
    {
        (*str)++;// .を飛ばす。
        if (('1' <= **str) && (**str <= '9'))
        {
            precision = ft_atoi_ex(*str);
            (*str)++;
        }
        else if (**str == '*')// *の時
        {
            precision = (int)va_arg(*ap, int);
            (*str)++;
        }
    
    }
    return (precision);
}

int ft_get_width(const char **str, va_list *ap)
{
    int width_digit;

    width_digit = 1;
    if (('1' <= **str) && (**str <= '9'))
    {
        width_digit = ft_atoi_ex(*str);
        (*str)++;
    }
    else if (**str == '*')
    {
        width_digit = (int)va_arg(*ap, int);
        (*str)++;
    }
    return (width_digit);
}

int ft_get_flag(const char **str)
{
    int flag;

    flag = 1;
    (*str)++;// %を飛ばす。
    if (**str == '0')
    {
        flag = 0;
        (*str)++;
        if (**str == '-')
            (*str)++;
    }
    else if (**str == '-')
    {
        flag = -1;
        (*str)++;
        if (**str == '0')
            (*str)++;
    }
    return (flag);
}

void ft_output(int flag, int width, int precision, int digit, int d)
{
    if (digit >= width && digit >= precision)
        ft_putnbr_fd(d);
    else if (precision > digit && precision >= width)
        ft_putnbr_ex(d, precision, digit);
    else if (width > digit && width > precision)
    {
        if (flag == 1)
        {
            ft_putspace(width, precision, digit, d);
            ft_putnbr_ex(d, precision, digit);
        }
        else if (flag == -1)
        {
            ft_putnbr_ex(d, precision, digit);
            ft_putspace(width, precision, digit, d);
        }
        else if (flag == 0)
        {
            if (precision != 1)
            {
                ft_putspace(width, precision, digit, d);
                ft_putnbr_ex(d, precision, digit);
            }
            else
            {
                ft_putspace(width, precision, digit, d);
                ft_putnbr_ex(d, precision, digit);
            }
        }
    }
}

/*void ft_input(const char **str)
{
    int         flag;
    int         width;
    int         precision;
    int         d;
    int         digit;

    digit = 0;    
    flag = ft_get_flag(&str);//フラグ
    width = ft_get_width(&str, &ap);//フィールド幅
    precision = ft_get_precision(&str, &ap);//精度
    d = ft_get_type(&str, &ap, &digit);
    //printf("flag:%d, width:%d, precision:%d, d:%d, digit:%d\n", flag, width, precision, d, digit);
    ft_output(flag, width, precision, digit, d); 
}*/

void ft_printf_str(const char **start, const char **str)
{
    while (**str != '%' && **str)
        (*str)++;
    write(1, *start, *str - *start);
}

int ft_printf(const char *str, ...)
{
    va_list     ap;
    const char  *start;
    int         flag;
    int         width;
    int         precision;
    int         d;
    int         digit;
    
    va_start(ap, str);
    while (*str)
    {
        start = str;
        if (*str != '%')
            ft_printf_str(&start, &str);
        else
        {
            //ft_input(&str);
            flag = ft_get_flag(&str);//フラグ
            width = ft_get_width(&str, &ap);//フィールド幅
            precision = ft_get_precision(&str, &ap);//精度
            d = ft_get_type(&str, &ap, &digit);
            //printf("flag:%d, width:%d, precision:%d, d:%d, digit:%d\n", flag, width, precision, d, digit);
            ft_output(flag, width, precision, digit, d);        
        }   
    }
    va_end(ap);
    return (1);
}
 
int main()
{
    ft_printf("[%d]", 123);
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
    ft_printf("[%-8.8d]", -123);
    printf("[%-8.8d]\n", -123);

    return (0);
}