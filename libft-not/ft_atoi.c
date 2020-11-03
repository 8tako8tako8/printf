/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauehara <tauehara@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 19:17:03 by tauehara          #+#    #+#             */
/*   Updated: 2020/10/07 19:55:29 by tauehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *s)
{
	int ret;
	int digit;
	int multiply;

	multiply = 1;
	while (*s == ' ' || (9 <= *s && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		multiply = (*s == '-' ? -1 : 1);
		s++;
	}
	digit = 0;
	while ('0' <= s[digit] && s[digit] <= '9')
		digit++;
	ret = 0;
	while (digit--)
	{
		ret += ((s[digit] - '0') * multiply);
		multiply *= 10;
	}
	return (ret);
}
