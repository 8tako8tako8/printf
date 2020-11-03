/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauehara <tauehara@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 23:46:32 by tauehara          #+#    #+#             */
/*   Updated: 2020/10/12 03:50:57 by tauehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int		n_i;
	t_uchar	*dst_uc;
	t_uchar	*src_uc;

	n_i = (int)n;
	dst_uc = (t_uchar *)dst;
	src_uc = (t_uchar *)src;
	while (n_i--)
	{
		*dst_uc++ = *src_uc++;
		if (*(src_uc - 1) == (t_uchar)c)
			break ;
	}
	while (n_i-- >= 0)
	{
		if (ft_isascii(*dst_uc))
			return (dst_uc);
		dst_uc++;
	}
	return (NULL);
}
