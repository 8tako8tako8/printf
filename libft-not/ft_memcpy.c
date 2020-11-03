/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauehara <tauehara@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 22:15:58 by tauehara          #+#    #+#             */
/*   Updated: 2020/10/10 17:59:00 by tauehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	cnt;
	char	*dst_c;
	char	*src_c;

	if (!dst && !src)
		return (dst);
	dst_c = (char *)dst;
	src_c = (char *)src;
	cnt = 0;
	while (cnt < n)
	{
		dst_c[cnt] = src_c[cnt];
		cnt++;
	}
	return (dst);
}
