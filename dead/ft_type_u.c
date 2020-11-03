/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorimot <kmorimot@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:42:03 by kmorimot          #+#    #+#             */
/*   Updated: 2020/11/03 13:46:20 by kmorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_type_u(const char **str, va_list *ap, t_fmt *fmt)
{
	unsigned int	tmp;

	fmt->u = (unsigned int)va_arg(*ap, unsigned int);
	tmp = fmt->u;
	if (tmp == 0)
		(fmt->digit)++;
	while (tmp != 0)
	{
		tmp = tmp / 10;
		(fmt->digit)++;
	}
	(*str)++;
}

void	ft_output_u(t_fmt *fmt, int *count)
{
	if ((fmt->width) == -1 && (fmt->precision) == 0 && (fmt->u) == 0)
		return ;
	else if ((fmt->digit) >= (fmt->width) && (fmt->digit) >= (fmt->precision))
		ft_putnbr_u_sub(fmt, count);
	else if ((fmt->precision) > (fmt->digit)
							&& (fmt->precision) >= (fmt->width))
		ft_putnbr_2u(fmt, count);
	else if ((fmt->width) > (fmt->digit) && (fmt->width) > (fmt->precision))
	{
		if ((fmt->flag) == 1)
			ft_putspace_nbr_u(fmt, count);
		else if ((fmt->flag) == -1)
			ft_putnbr_space_u(fmt, count);
		else if ((fmt->flag) == 0)
		{
			if ((fmt->precision) != -1)
				ft_putspace_nbr_u(fmt, count);
			else
				ft_putnbr_4u(fmt, count);
		}
	}
}

void	ft_putspace_u(t_fmt *fmt, int *count)
{
	int		margin;

	if ((fmt->precision) == 0 && (fmt->u) == 0 && (fmt->flag) == -1)
		margin = ft_width_max_u(fmt) + 1;
	else
		margin = ft_width_max_u(fmt);
	while (margin-- > 0)
		ft_count_putchar(' ', count);
}

void	ft_putnbr_u_sub(t_fmt *fmt, int *count)
{
	unsigned int	n;

	n = fmt->u;
	ft_putnbr_u(n, count);
}

void	ft_putnbr_u(unsigned int n, int *count)
{
	unsigned int	nbr;

	nbr = n;
	if (nbr >= 10)
		ft_putnbr_u(nbr / 10, count);
	ft_count_putchar(nbr % 10 + '0', count);
}
