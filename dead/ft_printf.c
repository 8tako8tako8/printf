/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorimot <kmorimot@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 01:10:08 by kmorimot          #+#    #+#             */
/*   Updated: 2020/11/03 19:51:55 by kmorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	const char	*start;
	t_fmt		fmt;
	int			count;

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
		{
			ft_init_fmt(&fmt);
			ft_input(&str, &ap, &count, &fmt);
		}
	}
	va_end(ap);
	return (count);
}

void	ft_printf_str(const char **start, const char **str, int *count)
{
	while (**str != '%' && **str)
		(*str)++;
	write(1, *start, *str - *start);
	*count += *str - *start;
}

void	ft_input(const char **str, va_list *ap, int *count, t_fmt *fmt)
{
	ft_get_flag(str, fmt);
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
				ft_get_type_and_output_x(str, ap, count, fmt);
		}
	}
}

void	ft_init_fmt(t_fmt *fmt)
{
	fmt->flag = 1;
	fmt->width = -1;
	fmt->precision = -1;
	fmt->s = NULL;
	fmt->p = NULL;
	fmt->digit = 0;
}

void	ft_output_pct(const char **str, t_fmt *fmt, int *count)
{
	if ((fmt->flag) == 1)
	{
		while ((fmt->width)-- - 1 > 0)
			ft_count_putchar(' ', count);
		ft_count_putchar('%', count);
	}
	else if ((fmt->flag) == -1)
	{
		ft_count_putchar('%', count);
		while ((fmt->width)-- - 1 > 0)
			ft_count_putchar(' ', count);
	}
	else if ((fmt->flag) == 0)
	{
		while ((fmt->width) - 1 > 0)
			ft_count_putchar('0', count);
		ft_count_putchar('%', count);
	}
	(*str)++;
}
