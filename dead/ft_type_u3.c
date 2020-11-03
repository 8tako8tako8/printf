/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_u3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorimot <kmorimot@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:48:38 by kmorimot          #+#    #+#             */
/*   Updated: 2020/11/03 13:49:22 by kmorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_4u(t_fmt *fmt, int *count)
{
	int				margin;
	unsigned int	nbr;

	nbr = (fmt->u);
	margin = (fmt->width) - (fmt->digit);
	while (margin-- > 0)
		ft_count_putchar('0', count);
	if (nbr >= 10)
		ft_putnbr_u(nbr / 10, count);
	ft_count_putchar(nbr % 10 + '0', count);
}
