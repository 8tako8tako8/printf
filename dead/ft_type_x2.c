/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorimot <kmorimot@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:35:04 by kmorimot          #+#    #+#             */
/*   Updated: 2020/11/03 13:36:37 by kmorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putspace_x(t_fmt *fmt, int *count)
{
	int		margin;

	margin = ft_width_max_x(fmt);
	while (margin-- > 0)
		ft_count_putchar(' ', count);
}

int		ft_width_max_x(t_fmt *fmt)
{
	int		width_max;

	if ((fmt->digit) >= (fmt->precision))
		width_max = (fmt->width) - (fmt->digit);
	else
		width_max = (fmt->width) - (fmt->precision);
	return (width_max);
}

void	ft_putspace_2x(t_fmt *fmt, int *count)
{
	while ((fmt->width)-- > 0)
		ft_count_putchar(' ', count);
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

void	ft_putnbr_3x(char **hex_cvt, t_fmt *fmt, int *count)
{
	int		margin;

	margin = (fmt->width) - (fmt->digit);
	while (margin-- > 0)
		ft_count_putchar('0', count);
	ft_putnbr_x(hex_cvt, fmt, count);
}
