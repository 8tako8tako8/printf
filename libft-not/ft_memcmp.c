/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauehara <tauehara@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 13:35:23 by tauehara          #+#    #+#             */
/*   Updated: 2020/10/10 18:31:03 by tauehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	t_uchar *s1_uc;
	t_uchar *s2_uc;

	s1_uc = (t_uchar *)s1;
	s2_uc = (t_uchar *)s2;
	while (n--)
	{
		if (*s1_uc != *s2_uc)
			return (*s1_uc - *s2_uc);
		s1_uc++;
		s2_uc++;
	}
	return (0);
}
