/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_X.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorimot <kmorimot@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 04:41:33 by kmorimot          #+#    #+#             */
/*   Updated: 2020/11/03 20:57:55 by kmorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_type_x(const char **str, va_list *ap, t_fmt *fmt)
{
	fmt->x = (unsigned int)va_arg(*ap, unsigned int);
	(*str)++;
}

void	ft_output_largex(t_fmt *fmt, int *count)
{
	char	hex_cvt[17];

	ft_hex_convert_largex(fmt, hex_cvt);
	if ((fmt->width) == -1 && (fmt->precision) == 0 && (fmt->x) == 0)
		return ;
	else if ((fmt->digit) >= (fmt->width) && (fmt->digit) >= (fmt->precision))
		ft_putnbr_x(hex_cvt, fmt, count);
	else if ((fmt->precision) > (fmt->digit)
								&& (fmt->precision) >= (fmt->width))
		ft_putnbr_2x(hex_cvt, fmt, count);
	else if ((fmt->width) > (fmt->digit) && (fmt->width) > (fmt->precision))
	{
		if ((fmt->flag) == 1)
			ft_putspace_nbr_x(fmt, hex_cvt, count);
		else if ((fmt->flag) == -1)
			ft_putnbr_space_x(fmt, hex_cvt, count);
		else if ((fmt->flag) == 0)
		{
			if ((fmt->precision) != -1)
				ft_putspace_nbr_x(fmt, hex_cvt, count);
			else
				ft_putnbr_3x(hex_cvt, fmt, count);
		}
	}
}

void	ft_hex_convert_largex(t_fmt *fmt, char *hex_cvt)
{
	unsigned int		y;
	char				*hex;
	int					j;

	hex = "0123456789ABCDEF";
	y = fmt->x;
	j = 0;
	if (y == 0)
	{
		hex_cvt[0] = hex[0];
		(fmt->digit)++;
	}
	while (y > 0)
	{
		j = y % 16;
		y = y / 16;
		hex_cvt[fmt->digit] = hex[j];
		(fmt->digit)++;
	}
}
