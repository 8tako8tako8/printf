/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauehara <tauehara@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 18:27:53 by tauehara          #+#    #+#             */
/*   Updated: 2020/10/10 19:06:44 by tauehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*head;

	head = (char *)s;
	while (*s)
		s++;
	while (*s != c)
	{
		if (s == head)
			return (NULL);
		s--;
	}
	return ((char *)s);
}
