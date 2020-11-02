
#include "ft_printf.h"

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