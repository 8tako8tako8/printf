/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_u2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorimot <kmorimot@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:49:32 by kmorimot          #+#    #+#             */
/*   Updated: 2020/11/03 13:52:57 by kmorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_2u(t_fmt *fmt, int *count)
{
	int				margin;
	unsigned int	nbr;

	nbr = (fmt->u);
	margin = (fmt->precision) - (fmt->digit);
	while (margin-- > 0)
		ft_count_putchar('0', count);
	if (nbr >= 10)
		ft_putnbr_u(nbr / 10, count);
	ft_count_putchar(nbr % 10 + '0', count);
}

void	ft_putspace_nbr_u(t_fmt *fmt, int *count)
{
	ft_putspace_u(fmt, count);
	if ((fmt->precision) != 0 || (fmt->u) != 0)
		ft_putnbr_3u(fmt, count);
	else
		ft_count_putchar(' ', count);
}

int		ft_width_max_u(t_fmt *fmt)
{
	int		width_max;

	if ((fmt->digit) >= (fmt->precision))
		width_max = (fmt->width) - (fmt->digit);
	else
		width_max = (fmt->width) - (fmt->precision);
	return (width_max);
}

void	ft_putnbr_space_u(t_fmt *fmt, int *count)
{
	ft_putnbr_3u(fmt, count);
	ft_putspace_u(fmt, count);
}

void	ft_putnbr_3u(t_fmt *fmt, int *count)
{
	int				margin;
	unsigned int	nbr;

	if ((fmt->precision) == 0 && (fmt->u) == 0)
		return ;
	else
	{
		nbr = (fmt->u);
		margin = (fmt->precision) - (fmt->digit);
		while (margin-- > 0)
			ft_count_putchar('0', count);
		if (nbr >= 10)
			ft_putnbr_u(nbr / 10, count);
		ft_count_putchar(nbr % 10 + '0', count);
	}
}
