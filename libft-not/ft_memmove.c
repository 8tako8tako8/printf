/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauehara <tauehara@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 02:49:35 by tauehara          #+#    #+#             */
/*   Updated: 2020/10/10 18:33:55 by tauehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_p;
	char	*src_p;

	if (!len)
		return (dst);
	dst_p = (char *)dst;
	src_p = (char *)src;
	if (dst_p < src_p)
	{
		while (len--)
			*dst_p++ = *src_p++;
	}
	else if (dst_p > src_p)
	{
		while (len--)
			dst_p[len] = src_p[len];
	}
	return (dst);
}
