/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauehara <tauehara@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:59:28 by tauehara          #+#    #+#             */
/*   Updated: 2020/10/11 02:53:38 by tauehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	num[12];
	int		ti;
	int		is_minus;

	if (n == 0)
	{
		ft_putstr_fd("0", fd);
		return ;
	}
	is_minus = (n < 0 ? 1 : 0);
	num[11] = '\0';
	ti = 10;
	while (n)
	{
		num[ti--] = '0' + (n % 10 < 0 ? (n % 10) * -1 : (n % 10));
		n /= 10;
	}
	if (is_minus)
		num[ti--] = '-';
	ft_putstr_fd(&num[ti + 1], fd);
}
