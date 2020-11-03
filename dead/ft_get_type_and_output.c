/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type_and_output.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorimot <kmorimot@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 04:10:46 by kmorimot          #+#    #+#             */
/*   Updated: 2020/11/03 04:14:34 by kmorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_type_and_output_d(const char **str, va_list *ap,
										int *count, t_fmt *fmt)
{
	ft_get_type_d(str, ap, fmt);
	ft_output_d(fmt, count);
}

void	ft_get_type_and_output_u(const char **str, va_list *ap,
										int *count, t_fmt *fmt)
{
	ft_get_type_u(str, ap, fmt);
	ft_output_u(fmt, count);
}

void	ft_get_type_and_output_c(const char **str, va_list *ap,
										int *count, t_fmt *fmt)
{
	ft_get_type_c(str, ap, fmt);
	ft_output_c(fmt, count);
}

void	ft_get_type_and_output_s(const char **str, va_list *ap,
										int *count, t_fmt *fmt)
{
	ft_get_type_s(str, ap, fmt);
	if ((fmt->s) == NULL)
		ft_output_null(fmt, count);
	else
		ft_output_s(fmt, count);
}

void	ft_get_type_and_output_p(const char **str, va_list *ap,
										int *count, t_fmt *fmt)
{
	ft_get_type_p(str, ap, fmt);
	if ((fmt->p) == NULL)
		ft_output_null_p(fmt, count);
	else
		ft_output_p(fmt, count);
}
