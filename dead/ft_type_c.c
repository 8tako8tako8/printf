/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorimot <kmorimot@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:27:10 by kmorimot          #+#    #+#             */
/*   Updated: 2020/11/03 13:28:36 by kmorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_type_c(const char **str, va_list *ap, t_fmt *fmt)
{
	fmt->c = (unsigned char)va_arg(*ap, int);
	(*str)++;
}

void	ft_output_c(t_fmt *fmt, int *count)
{
	char	c1;

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

void	ft_putspace_c(t_fmt *fmt, int *count)
{
	while ((((fmt->width)--) - 1) > 0)
		ft_count_putchar(' ', count);
}
