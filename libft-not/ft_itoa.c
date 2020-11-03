/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauehara <tauehara@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:23:45 by tauehara          #+#    #+#             */
/*   Updated: 2020/10/11 02:35:47 by tauehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	num[12];
	int		ni;
	int		is_minus;

	if (n == 0)
		return (ft_strdup("0"));
	is_minus = (n < 0 ? 1 : 0);
	num[11] = '\0';
	ni = 10;
	while (n)
	{
		num[ni--] = '0' + (n % 10 < 0 ? (n % 10) * -1 : (n % 10));
		n /= 10;
	}
	if (is_minus)
		num[ni--] = '-';
	return (ft_strdup(&num[ni + 1]));
}
