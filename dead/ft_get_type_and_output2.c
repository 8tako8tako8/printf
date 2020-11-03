/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type_and_output2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorimot <kmorimot@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 04:14:53 by kmorimot          #+#    #+#             */
/*   Updated: 2020/11/03 04:17:15 by kmorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_type_and_output_x(const char **str, va_list *ap,
										int *count, t_fmt *fmt)
{
	if (**str == 'x')
	{
		ft_get_type_x(str, ap, fmt);
		ft_output_x(fmt, count);
	}
	else if (**str == 'X')
	{
		ft_get_type_x(str, ap, fmt);
		ft_output_X(fmt, count);
	}
}
