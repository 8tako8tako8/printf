/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorimot <kmorimot@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:20:05 by kmorimot          #+#    #+#             */
/*   Updated: 2020/11/03 13:23:32 by kmorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putspace_nbr_d(t_fmt *fmt, int *count)
{
	ft_putspace_d(fmt, count);
	if ((fmt->precision) != 0 || (fmt->d) != 0)
		ft_putnbr_3d(fmt, count);
	else
		ft_count_putchar(' ', count);
}

void	ft_putspace_d(t_fmt *fmt, int *count)
{
	int		margin;

	if ((fmt->precision) == 0 && (fmt->d) == 0 && (fmt->flag) == -1)
		margin = ft_width_max_d(fmt) + 1;
	else
		margin = ft_width_max_d(fmt);
	while (margin-- > 0)
		ft_count_putchar(' ', count);
}

int		ft_width_max_d(t_fmt *fmt)
{
	int		width_max;

	if ((fmt->digit) >= (fmt->precision))
		width_max = (fmt->width) - (fmt->digit);
	else
		width_max = (fmt->width) - (fmt->precision);
	if ((fmt->d) < 0)
		width_max--;
	return (width_max);
}

void	ft_putnbr_space_d(t_fmt *fmt, int *count)
{
	ft_putnbr_3d(fmt, count);
	ft_putspace_d(fmt, count);
}

void	ft_putnbr_3d(t_fmt *fmt, int *count)
{
	int				margin;
	unsigned int	nbr;
	int				sign;

	if ((fmt->precision) == 0 && (fmt->d) == 0)
		return ;
	else
	{
		sign = 1;
		if ((fmt->d) < 0)
		{
			ft_count_putchar('-', count);
			sign *= -1;
		}
		margin = (fmt->precision) - (fmt->digit);
		while (margin-- > 0)
			ft_count_putchar('0', count);
		nbr = sign * (fmt->d);
		if (nbr >= 10)
			ft_putnbr_d(nbr / 10, count);
		ft_count_putchar(nbr % 10 + '0', count);
	}
}
