
void	ft_get_type_s(const char **str, va_list *ap, t_fmt *fmt)
{
    fmt->s = (char *)va_arg(*ap, char *);
    (*str)++;
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

void	ft_putstr_s(t_fmt *fmt, int len, int *count)
{
    char    *s1;

    s1 = fmt->s;
    write(1, s1, len);
    *count += len;
}

void	ft_putspace_s(t_fmt *fmt, int len, int *count)
{
    int margin;

    margin = (fmt->width) - len;
    while(margin-- > 0)
        ft_count_putchar(' ', count);
}