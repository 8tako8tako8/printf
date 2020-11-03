/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorimot <kmorimot@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:32:31 by kmorimot          #+#    #+#             */
/*   Updated: 2020/11/03 13:33:55 by kmorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_output_x(t_fmt *fmt, int *count)
{
	char	hex_cvt[17] = {};
	char	*p_hex_cvt;

	p_hex_cvt = hex_cvt;
	ft_hex_convert_x(fmt, &p_hex_cvt);
	if ((fmt->width) == -1 && (fmt->precision) == 0 && (fmt->x) == 0)
		return ;
	else if ((fmt->digit) >= (fmt->width) && (fmt->digit) >= (fmt->precision))
		ft_putnbr_x(&p_hex_cvt, fmt, count);
	else if ((fmt->precision) > (fmt->digit) && (fmt->precision) >= (fmt->width))
		ft_putnbr_2x(&p_hex_cvt, fmt, count);
	else if ((fmt->width) > (fmt->digit) && (fmt->width) > (fmt->precision))
	{
		if ((fmt->flag) == 1)
			ft_putspace_nbr_x(fmt, &p_hex_cvt, count);
		else if ((fmt->flag) == -1)
			ft_putnbr_space_x(fmt, &p_hex_cvt, count);
		else if ((fmt->flag) == 0)
		{
			if ((fmt->precision) != -1)
				ft_putspace_nbr_x(fmt, &p_hex_cvt, count);
			else
				ft_putnbr_3x(&p_hex_cvt, fmt, count);
		}
	}
}

void	ft_hex_convert_x(t_fmt *fmt, char **hex_cvt)
{
	unsigned int		y;
	char				hex[16] = "0123456789abcdef";
	int					j;

	y = fmt->x;
	j = 0;
	if (y == 0)
	{
		(*hex_cvt)[0] = hex[0];
		(fmt->digit)++;
	}
	while (y > 0)
	{
		j = y % 16;
		y = y / 16;
		(*hex_cvt)[fmt->digit] = hex[j];
		(fmt->digit)++;
	}
}

void	ft_putnbr_x(char **hex_cvt, t_fmt *fmt, int *count)
{
	int		digit1;

	digit1 = fmt->digit;
	*count += digit1;
	while (digit1 - 1 >= 0)
	{
		write(1, *hex_cvt + digit1 - 1, 1);
		digit1--;
	}
}

void	ft_putnbr_2x(char **hex_cvt, t_fmt *fmt, int *count)
{
	int		margin;

	margin = (fmt->precision) - (fmt->digit);
	while (margin-- > 0)
		ft_count_putchar('0', count);
	ft_putnbr_x(hex_cvt, fmt, count);
}

void	ft_putspace_nbr_x(t_fmt *fmt, char **hex_cvt, int *count)
{
	if ((fmt->precision) == 0 && (fmt->x) == 0)
		ft_putspace_2x(fmt, count);
	else
	{
		ft_putspace_x(fmt, count);
		ft_putnbr_2x(hex_cvt, fmt, count);
	}
}
