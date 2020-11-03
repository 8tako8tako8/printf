/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauehara <tauehara@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:18:21 by tauehara          #+#    #+#             */
/*   Updated: 2020/10/10 19:20:09 by tauehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	char *str_p;
	char *find_p;

	str_p = (char *)str;
	find_p = (char *)to_find;
	while (*str_p && *find_p && 0 < n - (str_p - str))
	{
		if (*str_p == *find_p)
		{
			str_p++;
			find_p++;
		}
		else
		{
			str_p -= find_p - (char *)to_find - 1;
			find_p = (char *)to_find;
		}
	}
	return (*find_p ? NULL : str_p - (find_p - (char *)to_find));
}
