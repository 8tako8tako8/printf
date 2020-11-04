/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorimot <kmorimot@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 04:02:48 by kmorimot          #+#    #+#             */
/*   Updated: 2020/11/04 14:21:17 by kmorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_precision(const char **str, va_list *ap, t_fmt *fmt)
{
	fmt->precision = -1;
	if (**str == '.')
	{
		(*str)++;
		fmt->precision = 0;
		if (('1' <= **str) && (**str <= '9'))
			fmt->precision = ft_atoi_ex(str);
		else if (**str == '0')
		{
			(*str)++;
			while (**str == '0')
				(*str)++;
			if (('1' <= **str) && (**str <= '9'))
				fmt->precision = ft_atoi_ex(str);
		}
		else if (**str == '*')
		{
			fmt->precision = (int)va_arg(*ap, int);
			if (fmt->precision < 0)
				fmt->precision = -1;
			(*str)++;
		}
	}
}

void	ft_get_width(const char **str, va_list *ap, t_fmt *fmt)
{
	fmt->width = -1;
	if (('1' <= **str) && (**str <= '9'))
		fmt->width = ft_atoi_ex(str);
	else if (**str == '0' || **str == '-')
	{
		while (**str == '0' || **str == '-')
			(*str)++;
	}
	else if (**str == '*')
	{
		fmt->width = (int)va_arg(*ap, int);
		if (fmt->width < 0)
		{
			fmt->flag = -1;
			fmt->width *= -1;
		}
		(*str)++;
	}
}

void	ft_get_flag(const char **str, t_fmt *fmt)
{
	fmt->flag = 1;
	(*str)++;
	if (**str == '0')
	{
		fmt->flag = 0;
		(*str)++;
		if (**str == '-')
		{
			(*str)++;
			fmt->flag = -1;
		}
		while (**str == '0' || **str == '-')
			(*str)++;
	}
	else if (**str == '-')
	{
		fmt->flag = -1;
		(*str)++;
		while (**str == '0' || **str == '-')
			(*str)++;
	}
	else if (**str == '%')
		ft_get_flag_pctpct(str, fmt);
}

void	ft_get_flag_pctpct(const char **str, t_fmt *fmt)
{
	fmt->flag = 2;
	(*str)++;
}
