/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauehara <tauehara@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 18:40:40 by tauehara          #+#    #+#             */
/*   Updated: 2020/10/10 17:53:24 by tauehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	char	*p;
	size_t	cnt;
	t_uint	u_ch;

	p = (char *)buf;
	u_ch = (t_uint)ch;
	cnt = 0;
	while (cnt < n)
	{
		*p = u_ch;
		p++;
		cnt++;
	}
	return (buf);
}
