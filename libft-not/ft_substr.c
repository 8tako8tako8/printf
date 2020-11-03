/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauehara <tauehara@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:55:03 by tauehara          #+#    #+#             */
/*   Updated: 2020/10/12 07:29:03 by tauehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	size;

	if (start >= (t_uint)ft_strlen(s))
	{
		if (!(p = (char *)malloc(sizeof(char))))
			return (NULL);
		*p = '\0';
		return (p);
	}
	size = (ft_strlen(&s[start]) > len ? len : ft_strlen(&s[start]));
	if (!(p = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	ft_strlcpy(p, &s[start], size + 1);
	return (p);
}
