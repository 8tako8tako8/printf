/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorimot <kmorimot@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:17:07 by kmorimot          #+#    #+#             */
/*   Updated: 2020/11/03 13:19:20 by kmorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_4d(t_fmt *fmt, int *count)
{
	int				margin;
	unsigned int	nbr;
	int				sign;

	sign = 1;
	if ((fmt->d) < 0)
	{
		ft_count_putchar('-', count);
		sign *= -1;
	}
	if (sign == -1)
		margin = (fmt->width) - (fmt->digit) - 1;
	else
		margin = (fmt->width) - (fmt->digit);
	while (margin-- > 0)
		ft_count_putchar('0', count);
	nbr = sign * (fmt->d);
	if (nbr >= 10)
		ft_putnbr_d(nbr / 10, count);
	ft_count_putchar(nbr % 10 + '0', count);
}
