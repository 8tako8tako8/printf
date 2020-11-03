/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauehara <tauehara@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:35:22 by tauehara          #+#    #+#             */
/*   Updated: 2020/10/11 01:48:30 by tauehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*p;

	len = ft_strlen(str);
	if (!(p = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	ft_strlcpy(p, str, len + 1);
	return (p);
}
