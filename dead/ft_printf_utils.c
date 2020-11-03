/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorimot <kmorimot@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 03:54:03 by kmorimot          #+#    #+#             */
/*   Updated: 2020/11/03 03:56:40 by kmorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_count_putchar(char c, int *count)
{
	ft_putchar(c);
	(*count)++;
}

int		ft_atoi_ex(const char **str)
{
	long long	number;
	int			i;

	number = 0;
	i = 0;
	while (ft_isdigit(**str))
	{
		number = number * 10;
		number += **str - '0';
		(*str)++;
	}
	return (number);
}
